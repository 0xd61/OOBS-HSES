import client.Client;
import messageServer.ADSBMessageServer;
import messageServer.Interfaces.ADSBMessageServerInterface;
import senser.Senser;

import java.util.Observer;

public class Starter
{

	public static void main(String[] args)
	{
		String urlString = "http://flugmon-it.hs-esslingen.de/subscribe/ads.sentence";
		Senser server = new Senser(urlString);

		Client client = new Client();
		server.addObserver(client);

		client.start();
		new Thread(server).start();
	}
}
