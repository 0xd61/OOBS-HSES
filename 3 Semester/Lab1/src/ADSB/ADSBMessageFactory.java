package ADSB;

import ADSB.Interfaces.ADSBMessageInterface;
import ADSB.Interfaces.ADSBMessageFactoryInterface;
import senser.ADSBSentence;
import senser.ADSBSentenceInterface;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageFactory implements ADSBMessageFactoryInterface
{
    @Override
    public ADSBMessage fromADSBSentence(ADSBSentence adsbSentence)
    {
        return null;
    }
}
