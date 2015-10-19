package ADSB.Interfaces;

import ADSB.ADSBMessage;
import senser.ADSBSentence;

/**
 * Created by Johannes on 12.10.2015.
 */
public interface ADSBMessageFactoryInterface
{
    public ADSBMessage fromADSBSentence(ADSBSentence adsbSentence);
}
