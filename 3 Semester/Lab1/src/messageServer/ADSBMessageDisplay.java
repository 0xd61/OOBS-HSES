package messageServer;

import messageServer.Interfaces.ADSBMessageInterface;
import messageServer.Interfaces.ADSBMessageServerObserverInterface;

import java.util.Observable;
import java.util.Observer;

/**
 * Created by Johannes on 09.11.2015.
 */
public class ADSBMessageDisplay extends ADSBMessageServerObserverInterface
{
    @Override
    public void update(Observable o, Object arg)
    {
        ADSBMessage message = ADSBMessage.class.cast(arg);
        if(message == null)
            return;

        if(arg instanceof ADSBAirbornePositionMessage)
        {
            ADSBAirbornePositionMessage msg = ADSBAirbornePositionMessage.class.cast(arg);

            StringBuilder sBuilder = new StringBuilder();
            sBuilder.append(String.format("%s Airborne Position Message\r\n" , msg.getIcao()));
            sBuilder.append(String.format("Type: \t\t %d\r\n",msg.getType()));
            sBuilder.append(String.format("Alti: \t\t %f\r\n",msg.getAltitude() * 0.3048));
            sBuilder.append(String.format("Lat : Lon: \t %d : %d\r\n",msg.getCprLatitude(), msg.getCprLongitude()));
            sBuilder.append(String.format("Format: \t %d\r\n",msg.getCprFormat()));
            //test
            System.out.println(sBuilder.toString());
            return;
        }

        if(arg instanceof  ADSBAirborneVelocityMessage)
        {
            ADSBAirborneVelocityMessage msg = ADSBAirborneVelocityMessage.class.cast(arg);
            StringBuilder sBuilder = new StringBuilder();
            sBuilder.append(String.format("%s Airborne Velocity Message\r\n" , msg.getIcao()));
            sBuilder.append(String.format("Speed: \t\t\t %s\r\n",msg.getSpeed()));
            sBuilder.append(String.format("Heading: \t\t %d\r\n",msg.getHeading()));
            sBuilder.append(String.format("Vertic: \t\t %d\r\n",msg.getVerticalSpeed()));

            System.out.println(sBuilder.toString());
            return;
        }

        if(arg instanceof  ADSBAircraftIdentificationMessage)
        {
            ADSBAircraftIdentificationMessage msg = ADSBAircraftIdentificationMessage.class.cast(arg);
            StringBuilder sBuilder = new StringBuilder();
            sBuilder.append(String.format("%s Aircraft Identification and Category Message\r\n" , msg.getIcao()));
            sBuilder.append(String.format("Ident: \t\t %s\r\n",msg.getAircraftId()));
            sBuilder.append(String.format("Categ: \t\t %d\r\n",msg.getCapability()));

            System.out.println(sBuilder.toString());
            return;
        }

        ADSBMessage msg = ADSBMessage.class.cast(arg);

        StringBuilder sBuilder = new StringBuilder();
        sBuilder.append(String.format("%s Other Message\r\n" , msg.getIcao()));
        sBuilder.append(String.format("Type: \t\t %d\r\n",msg.getType()));

        System.out.println(sBuilder.toString());
    }
}
