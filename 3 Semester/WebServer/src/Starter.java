import com.sun.net.httpserver.HttpServer;

import java.net.InetSocketAddress;

/**
 * Created by danie on 1/11/2016.
 */
public class Starter
{
    public static void main(String [] args) throws Exception {
        try
        {
            HttpServer server
                    = HttpServer.create(new InetSocketAddress(3333), 0);
            server.createContext("/resource", new ResourceHandler());
            server.setExecutor(null); // create a default executor
            server.start();
        }
        catch(Exception e)
            {
                System.out.println(e.getMessage());
            }

    }
}
