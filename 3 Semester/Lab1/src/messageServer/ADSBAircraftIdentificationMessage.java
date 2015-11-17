package messageServer;

import messageServer.Interfaces.ADSBAircraftIdentificationMessageInterface;

/**
 * Created by danie on 10/19/2015.
 */
public class ADSBAircraftIdentificationMessage extends ADSBMessage implements ADSBAircraftIdentificationMessageInterface
{
    private int emitterCategory;
    private String aircraftId;

    public ADSBAircraftIdentificationMessage(int emitterCategory, String aircraftId)
    {
        this.emitterCategory = emitterCategory;
        this.aircraftId = aircraftId;
    }

    @Override
    public int getEmitterCategory()
    {
        return emitterCategory;
    }

    @Override
    public String getAircraftId()
    {
        return aircraftId;
    }
}
