import client.Client;
import messageServer.ADSBMessageDisplay;
import messageServer.ADSBMessageObserverTest;
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
		ADSBMessageServer messageServer = new ADSBMessageServer();
		ADSBMessageDisplay test = new ADSBMessageDisplay();
		messageServer.addObserver(test);

		Client client = new Client();
		server.addObserver(client);
		server.addObserver(messageServer);

		client.start();
		new Thread(server).start();
	}
}
