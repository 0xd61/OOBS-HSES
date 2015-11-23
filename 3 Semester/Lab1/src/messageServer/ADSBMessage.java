package messageServer;

import messageServer.Interfaces.ADSBMessageInterface;

/**
 * Created by Johannes on 12.10.2015.
 */
public class ADSBMessage implements ADSBMessageInterface
{
    private String icao;
    private int type;
    private int ca;
    private  int df;
    private String payload;
    private int msgType;

    public ADSBMessage()
    {

    }

    @Override
    public String getTimestamp()
    {
        return null;
    }

    @Override
    public int getType()
    {
        return type;
    }

    @Override
    public String getIcao()
    {
        return icao;
    }

    @Override
    public int getDownlinkFormat()
    {
        return df;
    }

    @Override
    public int getCapability()
    {
        return ca;
    }

    @Override
    public int getMsgType() {return msgType;}

    @Override
    public void setType(int type)
    {
        this.type = type;
    }

    @Override
    public void setICAO(String icao)
    {
        this.icao = icao;
    }

    @Override
    public void setMsgType(int msgType) {this.msgType = msgType;}


}
