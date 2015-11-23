import GUI.ADSBMainWindow;
import client.Client;
import messageServer.ADSBMessageDisplay;
import messageServer.ADSBMessageMap;
import messageServer.ADSBMessageObserverTest;
import messageServer.ADSBMessageServer;
import messageServer.Interfaces.ADSBMessageServerInterface;
import senser.Senser;

import javax.swing.*;
import java.util.Observer;

public class Starter
{

	public static void main(String[] args)
	{
		String urlString = "http://flugmon-it.hs-esslingen.de/subscribe/ads.sentence";
		Senser server = new Senser(urlString);
		ADSBMessageServer messageServer = new ADSBMessageServer();
		ADSBMessageDisplay test = new ADSBMessageDisplay();
		ADSBMessageMap map = ADSBMessageMap.getInstance();
		messageServer.addObserver(test);
		messageServer.addObserver(map);

		Client client = new Client();
		server.addObserver(client);
		server.addObserver(messageServer);

		client.start();
		new Thread(server).start();

		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				try
				{
					UIManager.setLookAndFeel( UIManager.getSystemLookAndFeelClassName() );
				}
				catch ( Exception e )
				{
					e.printStackTrace();
				}

				ADSBMainWindow app = new ADSBMainWindow();
			}
		});
	}
}
