import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Set;

import redis.clients.jedis.Jedis;

/**
 * Created by danie on 1/11/2016.
 */
public class ResourceHandler implements HttpHandler
{
    Jedis jed;
    public ResourceHandler()
    {
        jed = new Jedis("localhost", 6379);
    }

    public void handle(HttpExchange t) throws IOException
    {
        StringBuilder response = new StringBuilder();
        Set<String> myKeys = jed.keys("*");
        if (myKeys.size() > 0)
        {
            for(String s:myKeys)
                response.append(jed.get(s)+"\r\n"); // create a string response
        }

        t.sendResponseHeaders(200, response.length());
        OutputStream os = t.getResponseBody();
        os.write(response.toString().getBytes());
        os.close();
    }
}
