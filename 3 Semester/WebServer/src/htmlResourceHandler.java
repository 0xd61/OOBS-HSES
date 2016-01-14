import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import redis.clients.jedis.Jedis;

import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.file.Files;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by danie on 1/14/2016.
 */
public class htmlResourceHandler implements HttpHandler
{
    public void handle(HttpExchange t) throws IOException
    {

        String content = new Scanner(new File("../HTMLmap.html")).useDelimiter("\\Z").next();
        System.out.println(content);
        t.sendResponseHeaders(200, content.length());
        OutputStream os = t.getResponseBody();
        os.write(content.getBytes());
        os.close();


    }
}


