import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import java.io.File;
import java.io.IOException;
import java.io.OutputStream;

import java.util.Scanner;


/**
 * Created by danie on 1/14/2016.
 */
public class HTMLHandler implements HttpHandler
{
    public void handle(HttpExchange t) throws IOException
    {
        try
        {
            System.out.println(HTMLHandler.class.getProtectionDomain().getCodeSource().getLocation());
            String content = new Scanner(new File("C:/Users/Daniel/Documents/GitHub/OOBS-HSES/3 Semester/WebServer/HTMLmap.html")).useDelimiter("\\Z").next();
            //String content = new Scanner(new File(getClass().getResource("HTMLmap.html").toString())).useDelimiter("\\Z").next();

            t.sendResponseHeaders(200, content.length());
            OutputStream os = t.getResponseBody();
            os.write(content.getBytes());
            os.close();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }

    }
}


