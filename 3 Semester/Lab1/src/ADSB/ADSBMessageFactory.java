package ADSB;

import ADSB.Interfaces.IADSBMessage;
import ADSB.Interfaces.IADSBMessageFactory;
import senser.ADSBSentenceInterface;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageFactory implements IADSBMessageFactory
{
    @Override
    public IADSBMessage fromADSBSentence(ADSBSentenceInterface adsbSentence)
    {
        return null;
    }
}
