package senser;
import com.sun.corba.se.impl.logging.OMGSystemException;

import java.util.Observable;

public class Senser extends Observable implements Runnable
{
	StreamingWebClient client;

	public Senser(String uri)
	{
		client = new StreamingWebClient(uri, 512);
	}

	private String getSentence()
	{
		//DONE: Define an regular expression to read in only relevant sentences
		//String filter = "\\d+\\.\\d+!ADS-B\\*[A-Z0-9]+";
		//TODO: Loesung fuer Regex finden
		String filter = "\\d+\\.\\d+!ADS-B\\*\\w{28}";
		// to find . or * you must use \\. or \\*;
		//System.out.println(client.readChunk(filter));
		return client.readChunk(filter);
	}
	
	public void run()
	{
		ADSBSentence sentence;
		
		//DONE: Create factory and display object
		ADSBSentenceFactory factory = new ADSBSentenceFactory();
		ADSBSentenceDisplay display =new ADSBSentenceDisplay();
		
		while (true)
		{
			sentence = factory.fromWebdisJson(getSentence());
			
			if (sentence != null)
			{
				//Display the sentence
				display.display(sentence);
				
				//Notify all observers
				setChanged();
				notifyObservers(sentence);
			}			
		}		
	}
}
