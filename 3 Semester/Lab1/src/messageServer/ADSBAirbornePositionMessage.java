package messageServer;

import messageServer.Interfaces.ADSBAirbornePositionMessageInterface;

/**
 * Created by Johannes on 19.10.2015.
 */
public class ADSBAirbornePositionMessage implements ADSBAirbornePositionMessageInterface
{
    private int surveillance;
    private int nicSupplement;
    private int altitude;
    private int timeFlag;
    private int cprFormat;
    private int cprLongitude;
    private int cprLatitude;

    public ADSBAirbornePositionMessage(int surveillance, int nicSupplement, int altitude, int timeFlag, int cprFormat, int cprLongitude, int cprLatitude)
    {
        this.surveillance = surveillance;
        this.nicSupplement = nicSupplement;
        this.altitude = altitude;
        this.timeFlag = timeFlag;
        this.cprFormat = cprFormat;
        this.cprLongitude = cprLongitude;
        this.cprLatitude = cprLatitude;
    }

    @Override
    public int getSurveillanceStatus()
    {
        return surveillance;
    }

    @Override
    public int getNicSupplement()
    {
        return nicSupplement;
    }

    @Override
    public int getAltitude()
    {
        return altitude;
    }

    @Override
    public int getTimeFlag()
    {
        return timeFlag;
    }

    @Override
    public int getCprFormat()
    {
        return cprFormat;
    }

    @Override
    public int getCprLongitude()
    {
        return cprLongitude;
    }

    @Override
    public int getCprLatitude()
    {
        return cprLatitude;
    }
}
