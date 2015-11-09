package messageServer;

import messageServer.Interfaces.ADSBMessageFactoryInterface;
import senser.ADSBSentence;
import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageFactory implements ADSBMessageFactoryInterface
{
    @Override
    public ADSBMessage fromADSBSentence(ADSBSentence adsbSentence)
    {
        String payloadInBin = HexBin.decode(adsbSentence.getPayload()).toString();

        String substringTypeCode = payloadInBin.substring(0,4);
        String substringSubtypeCode = payloadInBin.substring(5,7);
        String substringMessageType = payloadInBin.substring(8,55);

        int TypeCode = Integer.parseInt(substringTypeCode);
        int SubtypeCode = Integer.parseInt(substringSubtypeCode);

        //Airborne Position Message
        if(TypeCode == 0 || (TypeCode >= 9 && TypeCode <= 18)|| (TypeCode >= 20 && TypeCode <= 22))
        {
            //Messagetype parsen
            int surveillance = Integer.parseInt(payloadInBin.substring(5, 6));
            int nicSupplement = Integer.parseInt(payloadInBin.substring(7, 7));

            String strAltitude = payloadInBin.substring(8, 14);
            String strAltitude2 = payloadInBin.substring(16,19);
            int altitude = Integer.parseInt(strAltitude + strAltitude2);

            int timeFlag = Integer.parseInt(payloadInBin.substring(20, 20));
            int CPRFormat = Integer.parseInt(payloadInBin.substring(21, 21));
            int CPREncodedLat = Integer.parseInt(payloadInBin.substring(22, 38));
            int CPRLongitude = Integer.parseInt(payloadInBin.substring(39, 55));

            //QBit und Altitude Berechnung
            int qBit = Integer.parseInt(payloadInBin.substring(15, 15));
            if (qBit == 0)
                altitude *= 100;
            else
                altitude *= 25;


            ADSBMessage message = new ADSBAirbornePositionMessage(surveillance,nicSupplement,altitude,timeFlag,CPRFormat,CPRLongitude,CPREncodedLat);
            return message;
        }

        //Aircraft Identification Message
        if(TypeCode >= 1 && TypeCode <= 4)
        {
            char[] ascii = {'@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                            '[','\\',']','^','_',' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',
                            '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?'};
            int emitterCategory = Integer.parseInt(payloadInBin.substring(5,7));
            String aircraftId = payloadInBin.substring(8,55);

            aircraftId = Character.toString(ascii[Integer.parseInt(aircraftId.substring(0,5))]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(6,11))]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(12,17))]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(18,23))]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(24,29))]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(30,35))]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(36,41))]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(42,47))]);

            ADSBMessage message = new ADSBAircraftIdentificationMessage(emitterCategory,aircraftId);
        }

        //Aircraft Velocity Message
        if(TypeCode == 19 && (SubtypeCode >= 1 && SubtypeCode <=4))
        {
            int subtype = Integer.parseInt(payloadInBin.substring(5,7));
            int intentChange = Integer.parseInt(payloadInBin.substring(8,8));
            int reservedA = Integer.parseInt(payloadInBin.substring(9, 9));
            int navigationAccuracy = Integer.parseInt(payloadInBin.substring(10,12));


            int speed=0;
            int heading=0;
            int verticalRateSource=0;
            int verticalSpeed=0;

            ADSBMessage message = new ADSBAirborneVelocityMessage(subtype,intentChange,reservedA,navigationAccuracy,speed,heading,verticalRateSource,verticalSpeed);
            return message;
        }

        return null;
    }
}
