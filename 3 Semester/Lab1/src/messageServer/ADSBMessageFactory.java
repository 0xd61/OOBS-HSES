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
            int type = Integer.parseInt(payloadInBin.substring(0, 4));
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
            //Messagetype parsen

        }

        //Aircraft Velociry Message
        if(TypeCode == 19 && (SubtypeCode >= 1 && SubtypeCode <=4))
        {
            
        }

        return null;
    }
}
