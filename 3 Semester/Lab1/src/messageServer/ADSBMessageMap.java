package messageServer;

import messageServer.Interfaces.ADSBMessageServerObserverInterface;

import java.util.*;

/**
 * Created by danie on 11/17/2015.
 */
public class ADSBMessageMap extends ADSBMessageServerObserverInterface
{
    private HashMap <String, List<ADSBMessage>> icaoMap;
    public enum MsgType {positionMessage, identificationMessage, velocityMessage};

    public ADSBMessageMap()
    {
        icaoMap = new HashMap <String, List<ADSBMessage>>();
    }

    @Override
    public void update(Observable o, Object arg)
    {
        ADSBMessage message = ADSBMessage.class.cast(arg);
        if(message == null)
            return;

        List <ADSBMessage> myList;

        if (icaoMap.containsKey(message.getIcao()))
        {
            myList = icaoMap.get(message.getIcao());
            if (myList.size()==11)
            {
                ListIterator myiterator = myList.listIterator();
                //Iterator auf erstes Element bewegen
                myiterator.next();
                myiterator.remove();
            }

        }
        else
        {
            myList = new ArrayList<ADSBMessage>();
        }

        myList.add(message);
        icaoMap.put(message.getIcao(),myList);
    }

    List<ADSBMessage> getMessagetype(String icao, MsgType type)
    {
        List<ADSBMessage> tmpList = icaoMap.get(icao);
        List<ADSBMessage> filteredList = new ArrayList<ADSBMessage>();

        for(ADSBMessage element : tmpList)
        {
            if (MsgType.class.cast(element.getMsgType()) == type);
                filteredList.add(element);
        }

        return filteredList;
    }
}
