package messageServer.Interfaces;

import java.util.Observable;
import java.util.Observer;

/**
 * Created by Johannes on 12.10.2015.
 */
public abstract class ADSBMessageServerInterface extends Observable implements Observer
{
    public void Constructor(String uri)
    {

    }

    public ADSBMessageServerObserverInterface getObserver()
    {
        return(null);
    }

}
