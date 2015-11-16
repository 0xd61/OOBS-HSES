package messageServer;

import messageServer.Interfaces.ADSBMessageFactoryInterface;
import senser.ADSBSentence;
import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;

import java.math.BigInteger;


/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageFactory implements ADSBMessageFactoryInterface
{
    @Override
    public ADSBMessage fromADSBSentence(ADSBSentence adsbSentence)
    {


        //Payload in Bin�r umwandeln
        String payloadInBin = new BigInteger(adsbSentence.getPayload(),16).toString(2);
        while (payloadInBin.length()!= 56)
            payloadInBin = 0 + payloadInBin;
        //int test = payloadInBin.length();

        String substringTypeCode = payloadInBin.substring(0,5);
        String substringSubtypeCode = payloadInBin.substring(5,8);

        int TypeCode = Integer.parseInt(substringTypeCode,2);
        int SubtypeCode = Integer.parseInt(substringSubtypeCode,2);

        //Aircraft Position Message
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

            //TODO: Longitude und Latitude Berechnung
            //Kann nicht gerechnet werden, da zwei Messages ben�tigt werden


            //QBit und Altitude Berechnung
            int qBit = Integer.parseInt(payloadInBin.substring(15, 16),2);
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
            int emitterCategory = Integer.parseInt(payloadInBin.substring(5,8));

            //TODO: Optimierung mit Stringbuilder
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
            return message;
        }

        //Aircraft Velocity Message
        if(TypeCode == 19 && (SubtypeCode >= 1 && SubtypeCode <=4))
        {
            int subtype = Integer.parseInt(payloadInBin.substring(5,8),2);
            int intentChange = Integer.parseInt(payloadInBin.substring(8,9),2);
            int reservedA = Integer.parseInt(payloadInBin.substring(9, 19),2);
            int navigationAccuracy = Integer.parseInt(payloadInBin.substring(10,13),2);
            double speed = 0;
            double heading = 0;

            if (subtype == 1 || subtype == 2)
            {
                int eastWestDirection = Integer.parseInt(payloadInBin.substring(13,14),2);
                int eastWestVelocity = Integer.parseInt(payloadInBin.substring(14,24),2);
                int northSouthDirection = Integer.parseInt(payloadInBin.substring(24,25),2);
                int northSouthVelocity = Integer.parseInt(payloadInBin.substring(25,35),2);

                int weVel;
                int snVel;

                if (eastWestDirection == 0)
                    weVel = eastWestVelocity;
                else
                    weVel = -1 * eastWestVelocity;

                if (northSouthDirection == 0)
                    snVel = northSouthVelocity;
                else
                    snVel = -1 * northSouthVelocity;


                speed = Math.sqrt((double)weVel * (double)weVel + (double)snVel * (double)snVel);
                heading = Math.atan(((double)weVel/(double)snVel)*360.0/(2*Math.PI));
                if (heading < 0)
                    heading += 360;
            }
            //Nicht wirklich ben�tigt
            if (subtype == 3 || subtype == 4)
            {
                int headingStatus = Integer.parseInt(payloadInBin.substring(13,14),2);
                int speedType = Integer.parseInt(payloadInBin.substring(24,25),2);

                if (headingStatus == 0)
                    heading = 0;
                else
                    heading = 0;
            }

            int verticalRateSource= Integer.parseInt(payloadInBin.substring(35,36),2);
            int verticalSpeed = 0;

            ADSBMessage message = new ADSBAirborneVelocityMessage(subtype,intentChange,reservedA,navigationAccuracy,(int)speed,(int)heading,verticalRateSource,verticalSpeed);
            return message;
        }

        return null;
    }
}
