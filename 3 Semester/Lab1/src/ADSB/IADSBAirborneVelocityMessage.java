package ADSB;

/**
 * Created by Johannes on 08.10.2015.
 */
public interface IADSBAirborneVelocityMessage
{
    public abstract int getSubtype();
    public abstract int getIntentChange();
    public abstract int getReservedA();
    public abstract int getNavigationAccuracy();
    public abstract int getSpeed();
    public abstract int getHeading();
    public abstract int getVerticalRateSource();
    public abstract int getVerticalSpeed();


}
