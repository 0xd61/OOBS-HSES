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

        System.out.println(message.getType());
    }
}
