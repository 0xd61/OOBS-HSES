package ADSB.Interfaces;

/**
 * Created by Johannes on 12.10.2015.
 */
public interface IADSBMessageServer extends IADSBMessageObserable, IADSBMessageServerObserver
{
    public void Constructor(String uri);
    public IADSBMessageServerObserver getObserver();
}
