package ADSB.Interfaces;

/**
 * Created by Johannes on 12.10.2015.
 */
public interface ADSBMessageServerInterface extends ADSBMessageObserableInterface, ADSBMessageServerObserverInterface
{
    public void Constructor(String uri);
    public ADSBMessageServerObserverInterface getObserver();
}
