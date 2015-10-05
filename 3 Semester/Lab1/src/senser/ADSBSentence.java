package senser;
import java.text.SimpleDateFormat;
import java.util.Date;

public class ADSBSentence implements ADSBSentenceInterface
{
	//TODO: Create relevant fields

	public ADSBSentence(String timestamp, String dfca, String icao, String payload, String parity)
	{
		//TODO: Fill relevant fields
	}

	//TODO: Create relevant getter and setter methods
	
	//TODO: Overwrite toString() method to print our relevant fields
	public String toString()
	{
		//1379574427.9127481			
		String[] times = this.getTimestamp().split("\\."); 
		
		//TODO: Define date format
		SimpleDateFormat dateFormat = ...;
		//TODO: Create a DAte object
		Date date = ...;
		//Create time string
		String time = dateFormat.format(date) + "." + times[1];
		
		return "Time:\t\t " + time + "\n" +
				"Dfca:\t\t " + this.getDfca() + "\n" +
				"Originator:\t " + this.getIcao() + "\n" +
				"Payload:\t " + this.getPayload() + "\n" +
				"Parity:\t\t " + this.getParity() + "\n";
	}
}
