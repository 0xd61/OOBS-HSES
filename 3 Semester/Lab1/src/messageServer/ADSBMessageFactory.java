package messageServer;

import com.sun.deploy.security.ValidationState;
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
        //Payload in Binär umwandeln
        byte[] payloadByteArray = HexBin.decode(adsbSentence.getPayload());

        StringBuilder stringBuilder = new StringBuilder();
        StringBuilder binData;

        for(int i = 0;i<payloadByteArray.length;i++)
        {
            binData = new StringBuilder();
            binData.append(Integer.toString(payloadByteArray[i] & 0xFF, 2));
            if(binData.toString().length() < 8)
            {
                int nullen = 8 - binData.toString().length();
                for(int j = 0;j<nullen;j++)
                {
                    binData.insert(0,'0');
                }
            }

            stringBuilder.append(binData.toString());
        }

        String payloadInBin = stringBuilder.toString();
        //int binSize = payloadInBin.length(); //Nur für Debug

        String substringTypeCode = payloadInBin.substring(0,5);
        String substringSubtypeCode = payloadInBin.substring(5,8);
        //String substringMessageType = payloadInBin.substring(8,56); NICHT BENÖTIGT

        int TypeCode = Integer.parseInt(substringTypeCode,2);
        int SubtypeCode = Integer.parseInt(substringSubtypeCode,2);

        //Airborne Position Message
        if(TypeCode == 0 || (TypeCode >= 9 && TypeCode <= 18)|| (TypeCode >= 20 && TypeCode <= 22))
        {
            //Messagetype parsen
            int surveillance = Integer.parseInt(payloadInBin.substring(5, 7),2);
            int nicSupplement = Integer.parseInt(payloadInBin.substring(7, 8),2);

            String strAltitude = payloadInBin.substring(8, 15);
            String strAltitude2 = payloadInBin.substring(16,20);
            int altitude = Integer.parseInt(strAltitude + strAltitude2,2);

            int timeFlag = Integer.parseInt(payloadInBin.substring(20, 21),2);
            int CPRFormat = Integer.parseInt(payloadInBin.substring(21, 22),2);
            int CPREncodedLat = Integer.parseInt(payloadInBin.substring(22, 39),2);
            int CPRLongitude = Integer.parseInt(payloadInBin.substring(39, 56),2);

            //QBit und Altitude Berechnung
            int qBit = Integer.parseInt(payloadInBin.substring(15, 16),2);
            if (qBit == 0)
                altitude *= 100;
            else
                altitude *= 25;


            ADSBMessage message = new ADSBAirbornePositionMessage(surveillance,nicSupplement,altitude,timeFlag,CPRFormat,CPRLongitude,CPREncodedLat);
            message.setType(TypeCode);
            message.setICAO(adsbSentence.getIcao());
            return message;
        }

        //Aircraft Identification Message
        if(TypeCode >= 1 && TypeCode <= 4)
        {
            char[] ascii = {'@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                            '[','\\',']','^','_',' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',
                            '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?'};
            int emitterCategory = Integer.parseInt(payloadInBin.substring(5,8));

            String aircraftId = payloadInBin.substring(8,56);
            aircraftId = Character.toString(ascii[Integer.parseInt(aircraftId.substring(0,6),2)]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(6,12),2)]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(12,18),2)]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(18,24),2)]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(24,30),2)]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(30,36),2)]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(36,42),2)]) +
                         Character.toString(ascii[Integer.parseInt(aircraftId.substring(42,48),2)]);

            ADSBMessage message = new ADSBAircraftIdentificationMessage(emitterCategory,aircraftId);
            message.setType(TypeCode);
            message.setICAO(adsbSentence.getIcao());
            return message;
        }

        //Aircraft Velocity Message
        if(TypeCode == 19 && (SubtypeCode >= 1 && SubtypeCode <=4))
        {
            int subtype = Integer.parseInt(payloadInBin.substring(5,8));
            int intentChange = Integer.parseInt(payloadInBin.substring(8,9));
            int reservedA = Integer.parseInt(payloadInBin.substring(9, 19));
            int navigationAccuracy = Integer.parseInt(payloadInBin.substring(10,13));

            if (subtype == 1 || subtype == 2)
            {
                int eastWestDirection;
                int eastWestVerlocity;
                int northSouthDirection;
                int northSouthVelocity;

            }
            if (subtype == 3 || subtype == 4)
            {

            }
            int heading = 0;
            int speed = 0;

            int verticalRateSource= Integer.parseInt(payloadInBin.substring(35,36),2);
            int verticalSpeed = 0;

            ADSBMessage message = new ADSBAirborneVelocityMessage(subtype,intentChange,reservedA,navigationAccuracy,speed,heading,verticalRateSource,verticalSpeed);
            message.setType(TypeCode);
            message.setICAO(adsbSentence.getIcao());
            return message;
        }

        return null;
    }
}
