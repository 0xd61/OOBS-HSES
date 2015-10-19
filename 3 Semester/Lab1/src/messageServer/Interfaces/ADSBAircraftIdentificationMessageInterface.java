package messageServer.Interfaces;

/**
 * Created by Johannes on 08.10.2015.
 */
public interface ADSBAircraftIdentificationMessageInterface extends ADSBMessageInterface
{
    public int getEmitterCategory();
    public String getAircraftId();
}
