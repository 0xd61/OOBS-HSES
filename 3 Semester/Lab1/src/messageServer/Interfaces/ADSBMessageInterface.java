package messageServer.Interfaces;

import messageServer.ADSBAirbornePositionMessage;

/**
 * Created by Johannes on 12.10.2015.
 */
public interface ADSBMessageInterface
{
    //public void constructor(String icao, int type,int df, int ca, String payload);
    public String getTimestamp();
    public int getType();
    public String getIcao();
    public int getDownlinkFormat();
    public int getCapability();

    public void setICAO(String icao);
    public void setType(int type);

}
