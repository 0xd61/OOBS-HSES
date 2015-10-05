package senser;
import java.util.regex.Pattern;


public class ADSBSentenceFactory implements ADSBSentenceFactoryInterface
{
	//TODO: define a regular express to filter only relevant messages: 
	//{"subscribe":["message","ads.sentence","1379574427.9127481!ADS-B*8D40675258BDF05CDBFB59DA7D6F;\r\n"]}
	private static final String patAdsbJson = ...;

	@Override
	public ADSBSentence fromWebdisJson(String json)
	{		
		if ( Pattern.matches ( patAdsbJson, json ) ) 
		{					
			//TODO: Get distinct values from the json string
			String timestamp = ...;									
			String dfca 	 = ...;					
			String icao 	 = ...;			
			String payload 	 = ...;			
			String parity 	 = ...;
			
			return new ADSBSentence(timestamp, dfca, icao, payload, parity);
		}
		else
		{
			return null;
		}
	}
}
