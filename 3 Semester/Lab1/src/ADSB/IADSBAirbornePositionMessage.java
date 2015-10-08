package ADSB;

/**
 * Created by Johannes on 08.10.2015.
 */
public interface IADSBAirbornePositionMessage
{
    public abstract int getSurveillanceStatus();
    public abstract int getNicSupplement();
    public abstract int getAltitude();
    public abstract int getTimeFlag();
    public abstract int getCprFormat();
    public abstract int getCprLongitude();
    public abstract int getCprLatitude();
}
