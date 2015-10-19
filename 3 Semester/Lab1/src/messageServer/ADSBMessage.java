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

    public ADSBMessage()
    {

    }

    public ADSBMessage (String icao, int type,int df, int ca, String payload)
    {
        this.icao = icao;
        this.type = type;
        this.ca = ca;
        this.payload = payload;
        this.df = df;
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
}
