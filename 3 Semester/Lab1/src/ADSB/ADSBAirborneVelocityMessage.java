package ADSB;

import ADSB.Interfaces.ADSBAirborneVelocityMessageInterface;

/**
 * Created by danie on 10/19/2015.
 */
public class ADSBAirborneVelocityMessage implements ADSBAirborneVelocityMessageInterface
{
    private int subtype;
    private int intentChange;
    private int reservedA;
    private int navigationAccuracy;
    private int speed;
    private int heading;
    private int verticalRateSource;
    private int verticalSpeed;

    public ADSBAirborneVelocityMessage(int subtype, int intentChange, int reservedA, int navigationAccuracy, int speed, int heading, int verticalRateSource, int verticalSpeed)
    {
        this.subtype = subtype;
        this.intentChange = intentChange;
        this.reservedA = reservedA;
        this.navigationAccuracy = navigationAccuracy;
        this.speed = speed;
        this.heading = heading;
        this.verticalRateSource = verticalRateSource;
        this.verticalSpeed = verticalSpeed;
    }

    @Override
    public int getSubtype()
    {
        return subtype;
    }

    @Override
    public int getIntentChange()
    {
        return intentChange;
    }

    @Override
    public int getReservedA()
    {
        return reservedA;
    }

    @Override
    public int getNavigationAccuracy()
    {
        return navigationAccuracy;
    }

    @Override
    public int getSpeed()
    {
        return speed;
    }

    @Override
    public int getHeading()
    {
        return heading;
    }

    @Override
    public int getVerticalRateSource()
    {
        return verticalRateSource;
    }

    @Override
    public int getVerticalSpeed()
    {
        return verticalSpeed;
    }
}
