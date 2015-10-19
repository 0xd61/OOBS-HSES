package messageServer;

import messageServer.Interfaces.ADSBMessageFactoryInterface;
import senser.ADSBSentence;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessageFactory implements ADSBMessageFactoryInterface
{
    @Override
    public ADSBMessage fromADSBSentence(ADSBSentence adsbSentence)
    {
        int payloadInInteger = Integer.parseInt(adsbSentence.getPayload());
        String payloadInBin = Integer.toBinaryString(payloadInInteger);

        String substringMessageType = payloadInBin.substring(0,4);
        int messageType = Integer.parseInt(substringMessageType);

        switch (messageType)
        {
            case 0:
                //POSITION MESSAGE.
                break;

            
        }


        return null;
    }
}
