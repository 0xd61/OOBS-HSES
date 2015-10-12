package ADSB;

/**
 * Created by Johannes on 08.10.2015.
 */
public interface IADSBAirborneVelocityMessage
{
    public int getSubtype();
    public int getIntentChange();
    public int getReservedA();
    public int getNavigationAccuracy();
    public int getSpeed();
    public int getHeading();
    public int getVerticalRateSource();
    public int getVerticalSpeed();


}
