package messageServer;

import messageServer.Interfaces.ADSBMessageFactoryInterface;
import messageServer.Interfaces.ADSBMessageInterface;
import messageServer.Interfaces.ADSBMessageServerInterface;
import messageServer.Interfaces.ADSBMessageServerObserverInterface;
import senser.ADSBSentence;

import java.util.Observable;
import java.util.Observer;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageServer extends ADSBMessageServerInterface
{
    private ADSBMessageFactoryInterface messageFactory = new ADSBMessageFactory();

    @Override
    public void Constructor(String uri)
    {
    }

    @Override
    public ADSBMessageServerObserverInterface getObserver()
    {
        return (ADSBMessageServerObserverInterface)this;
    }

    @Override
    public void update(Observable o, Object arg)
    {
        ADSBSentence sentence = ADSBSentence.class.cast(arg);

        ADSBMessageInterface adsbMessage = messageFactory.fromADSBSentence(sentence);

        setChanged();
        notifyObservers(adsbMessage);
    }
}
