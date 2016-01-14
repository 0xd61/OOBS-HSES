import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import java.io.IOException;
import java.io.OutputStream;

/**
 * Created by danie on 1/11/2016.
 */
public class ResourceHandler implements HttpHandler
{
    public void handle(HttpExchange t) throws IOException
    {
        String response ="test"; // create a string response
        t.sendResponseHeaders(200, response.length());
        OutputStream os = t.getResponseBody();
        os.write(response.getBytes());
        os.close();
    }
}
