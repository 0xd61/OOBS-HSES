package messageServer.Interfaces;

/**
 * Created by Johannes on 08.10.2015.
 */
public interface ADSBAirbornePositionMessageInterface
{
    public int getSurveillanceStatus();
    public int getNicSupplement();
    public int getAltitude();
    public int getTimeFlag();
    public int getCprFormat();
    public int getCprLongitude();
    public int getCprLatitude();
}
