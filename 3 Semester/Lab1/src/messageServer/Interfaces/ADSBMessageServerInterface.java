package messageServer.Interfaces;

import java.util.Observable;
import java.util.Observer;

/**
 * Created by Johannes on 12.10.2015.
 */
public abstract class ADSBMessageServerInterface extends Observable implements Observer
{
    public ADSBMessageServerObserverInterface getObserver()
    {
        return(null);
    }

}
