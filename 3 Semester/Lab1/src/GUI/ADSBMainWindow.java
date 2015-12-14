package GUI;

import messageServer.ADSBAirbornePositionMessage;
import messageServer.ADSBMessage;
import messageServer.ADSBMessageMap;

import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Johannes on 23.11.2015.
 */
public class ADSBMainWindow extends  JFrame
{
    private JPanel contentPanel;
    private JTabbedPane tabbedPane1;
    private JList listActiveFlights;
    private JTextField textField1;

    private Timer timer;

    public ADSBMainWindow()
    {

        super("ADSB Main Window");
        setContentPane(contentPanel);
        setSize(800,600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        InitTimer(2000);

        listActiveFlights.addListSelectionListener(new ListSelectionListener()
        {
            @Override
            public void valueChanged(ListSelectionEvent e)
            {
                try
                {
                    String icao = listActiveFlights.getSelectedValue().toString();

                    ADSBAirbornePositionMessage msg = ADSBAirbornePositionMessage.class.cast(ADSBMessageMap.getInstance().getLastMessageOfType(icao, ADSBMessageMap.MsgType.positionMessage));


                    textField1.setText(new Integer(msg.getAltitude()).toString());
                }
                catch(Exception ex)
                {

                }
            }
        });

        // buttonUpdate.addActionListener(new ButtonUpdate_Clicked());

    }

    private void InitTimer(int updateTimeInMilliseconds)
    {
        timer = new Timer();
        timer.scheduleAtFixedRate(new TimerTask()
        {
            public void run()
            {
                listActiveFlights.removeAll();
                List<String> flights = ADSBMessageMap.getInstance().getAllActive();
                DefaultListModel model = new DefaultListModel();

                for(String s : flights)
                    model.addElement(s);

                listActiveFlights.setModel(model);
            }
        }
                ,1000,updateTimeInMilliseconds);
    }

    /*
    public class ButtonUpdate_Clicked implements  ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent e)
        {
            DefaultTreeModel model = (DefaultTreeModel) treeFlights.getModel();
            DefaultMutableTreeNode root = (DefaultMutableTreeNode) model.getRoot();
            model.insertNodeInto(new DefaultMutableTreeNode("another_child"), root, root.getChildCount());
        }
    }
    */
}


