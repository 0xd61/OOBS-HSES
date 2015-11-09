package messageServer;

import messageServer.Interfaces.ADSBMessageFactoryInterface;
import messageServer.Interfaces.ADSBMessageInterface;
import messageServer.Interfaces.ADSBMessageServerInterface;
import messageServer.Interfaces.ADSBMessageServerObserverInterface;

import java.util.Observable;
import java.util.Observer;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageServer implements ADSBMessageServerInterface
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
    public void update()
    {

    }

    @Override
    public ADSBMessageInterface getMessage()
    {
        return null;
    }
}
