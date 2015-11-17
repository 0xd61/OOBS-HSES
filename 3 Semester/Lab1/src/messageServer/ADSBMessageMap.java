package messageServer;

import messageServer.Interfaces.ADSBMessageServerObserverInterface;

import java.util.*;

/**
 * Created by danie on 11/17/2015.
 */
public class ADSBMessageMap extends ADSBMessageServerObserverInterface
{
    private HashMap <String, List<ADSBMessage>> icaoMap;

    public ADSBMessageMap()
    {
        icaoMap = new HashMap <String, List<ADSBMessage>>();
    }

    @Override
    public void update(Observable o, Object arg)
    {
        ADSBMessage message = ADSBMessage.class.cast(arg);
        List <ADSBMessage> myList;

        if (icaoMap.containsKey(message.getIcao()))
        {
            myList = icaoMap.get(message.getIcao());
            if (myList.size()==10)
            {
                ListIterator myiterator = myList.listIterator();
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
}
