import com.sun.net.httpserver.HttpServer;

import java.net.InetSocketAddress;

/**
 * Created by danie on 1/11/2016.
 */
public class Starter
{
    static HttpServer server;
    public static void main(String [] args) throws Exception {
        try
        {
            server = HttpServer.create(new InetSocketAddress(3333), 0);
            server.createContext("/active.kml", new ResourceHandler());
            server.createContext("/", new htmlResourceHandler());
            server.setExecutor(null); // create a default executor
            server.start();
        }
        catch(Exception e)
            {
                System.out.println(e.getMessage());
            }
        while (true)
        {

        }

    }
}
