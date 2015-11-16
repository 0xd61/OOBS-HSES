import client.Client;
import messageServer.ADSBMessageDisplay;
import messageServer.ADSBMessageServer;
import senser.Senser;

public class Starter
{

	public static void main(String[] args)
	{
		String urlString = "http://flugmon-it.hs-esslingen.de/subscribe/ads.sentence";
		Senser server = new Senser(urlString);

		ADSBMessageServer messageServer = new ADSBMessageServer();

		// Observer zum MessageServer hinzufügen.
		ADSBMessageDisplay messageDisplay = new ADSBMessageDisplay();
		messageServer.addObserver(messageDisplay);

		Client client = new Client();

		// Observer zum Senser hinzufügen.
		server.addObserver(client);
		server.addObserver(messageServer);

		client.start();
		new Thread(server).start();
	}
}
