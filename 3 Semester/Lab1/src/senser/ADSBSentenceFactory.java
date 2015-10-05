package senser;
import java.util.regex.Pattern;


public class ADSBSentenceFactory implements ADSBSentenceFactoryInterface
{
	//DONE: define a regular express to filter only relevant messages:
	//{"subscribe":["message","ads.sentence","1379574427.9127481!ADS-B*8D40675258BDF05CDBFB59DA7D6F;\r\n"]}
	private static final String patAdsbJson = "\\d+\\.\\d+!ADS-B\\*[A-Z0-9]+";

	@Override
	public ADSBSentence fromWebdisJson(String json)
	{		
		if ( Pattern.matches ( patAdsbJson, json ) ) 
		{					
			//DONE: Get distinct values from the json string
			String timestamp = json.split("\\d+\\.\\d+")[0];
			String dfca 	 = json.split("\\*\\w{2}")[0].replace("*","");

			String jsonNEU = json.split("\\*")[1];
			String icao 	 = jsonNEU.substring(2,8);
			String payload 	 = jsonNEU.substring(9,23);
			String parity 	 = jsonNEU.substring(24,30);

			return new ADSBSentence(timestamp, dfca, icao, payload, parity);
		}
		else
		{
			return null;
		}
	}
}
