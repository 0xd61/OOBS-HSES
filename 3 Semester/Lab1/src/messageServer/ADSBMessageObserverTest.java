package messageServer;

import messageServer.Interfaces.ADSBMessageInterface;

import java.util.Observable;
import java.util.Observer;

/**
 * Created by Johannes on 09.11.2015.
 */
public class ADSBMessageObserverTest implements Observer
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
            System.out.println(msg.getAltitude() * 0.3048);
        }

    }
}
