import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Iterator;
import java.util.Set;

import redis.clients.jedis.Jedis;

/**
 * Created by danie on 1/11/2016.
 */
public class KmlHandler implements HttpHandler
{
    Jedis jed;
    public KmlHandler()
    {
        jed = new Jedis("localhost", 6379);
    }

    public void handle(HttpExchange t) throws IOException
    {
        StringBuilder response = new StringBuilder();
        Set<String> myKeys = jed.keys("*");

        /*if (myKeys.size() > 0)
        {
            for (String s : myKeys)
            {
                //response.append(jed.get(s) + "\r\n"); // create a string response


                t.sendResponseHeaders(200, response.length());
                OutputStream os = t.getResponseBody();
                //os.write(response.toString().getBytes());
                os.write(jed.get(s).toString().getBytes());
                os.close();
            }
        }*/
        t.sendResponseHeaders(200, response.length());
        OutputStream os = t.getResponseBody();
        if(myKeys.isEmpty())
        {
            os.write("No Key available!".getBytes());
        }
        else
        {
            Iterator<String> it = myKeys.iterator();
            String key = it.next();
            os.write(jed.get(key).getBytes());
            jed.del(key);
        }
        os.close();
    }
}
