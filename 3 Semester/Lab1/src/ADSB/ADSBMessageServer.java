package ADSB;

import ADSB.Interfaces.IADSBMessage;
import ADSB.Interfaces.IADSBMessageServer;
import ADSB.Interfaces.IADSBMessageServerObserver;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageServer implements IADSBMessageServer
{
    @Override
    public void Constructor(String uri)
    {

    }

    @Override
    public IADSBMessageServerObserver getObserver()
    {
        return null;
    }

    @Override
    public void update()
    {

    }

    @Override
    public IADSBMessage getMessage()
    {
        return null;
    }
}
