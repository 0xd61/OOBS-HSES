package ADSB;

/**
 * Created by Johannes on 08.10.2015.
 */
public interface IADSBAircraftIdentificationMessage
{
    public abstract int getEmitterCategory();
    public abstract String getAircraftId();
}
