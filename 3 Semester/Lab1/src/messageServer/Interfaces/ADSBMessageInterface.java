package messageServer.Interfaces;

import messageServer.ADSBAirbornePositionMessage;

import java.util.Date;

/**
 * Created by Johannes on 12.10.2015.
 */
public interface ADSBMessageInterface
{
    //public void constructor(String icao, int type,int df, int ca, String payload);
    public Date getTimestamp();
    public int getType();
    public String getIcao();
    public int getDownlinkFormat();
    public int getCapability();
    public int getMsgType();

    public void setType(int type);
    public void setICAO(String icao);
    public void setMsgType(int msgType);
    public void setTimestamp (Date timestamp);
}
