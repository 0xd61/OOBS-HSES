import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import java.io.*;

/**
 * Created by danie on 1/15/2016.
 */
public class ResourceHandler implements HttpHandler
{
    public void handle(HttpExchange t) throws IOException
    {
        try
        {
            // add the required response header for a png file
            Headers h = t.getResponseHeaders();
            h.add("Content-Type", "file/png");

            // a png (you provide your own!)
            File file = new File("C:/Users/Daniel/Documents/GitHub/OOBS-HSES/3 Semester/WebServer/Icons/locator.png");
            byte[] bytearray = new byte[(int) file.length()];
            FileInputStream fis = new FileInputStream(file);
            BufferedInputStream bis = new BufferedInputStream(fis);
            bis.read(bytearray, 0, bytearray.length);

            // ok, we are ready to send the response.
            t.sendResponseHeaders(200, file.length());
            OutputStream os = t.getResponseBody();
            os.write(bytearray, 0, bytearray.length);
            os.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
