package messageServer;

import messageServer.Interfaces.ADSBMessageInterface;
import messageServer.Interfaces.ADSBMessageServerInterface;
import messageServer.Interfaces.ADSBMessageServerObserverInterface;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageServer implements ADSBMessageServerInterface
{
    @Override
    public void Constructor(String uri)
    {

    }

    @Override
    public ADSBMessageServerObserverInterface getObserver()
    {
        return null;
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
