package GUI;

import messageServer.*;

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
    private JTextField Height; //hello
    private JTextField Speed;
    private JTextField ICAO;
    private JTextField Latitude;
    private JTextField Longitude;
    private JTextField textField1;

    private Timer timer;
    private Timer flightInfoUpdateTimer;

    private String currentICAO;

    public ADSBMainWindow()
    {

        super("ADSB Main Window");
        setContentPane(contentPanel);
        setSize(800,600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        InitTimer(5000);
        FlightInfoUpdateTimerTick(1000);

        listActiveFlights.addListSelectionListener(new ListSelectionListener()
        {
            @Override
            public void valueChanged(ListSelectionEvent e)
            {
                try
                {
                    currentICAO = listActiveFlights.getSelectedValue().toString();
                    UpdateFlightInfo();
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
                UpdateFlightList();
            }
        }
                ,1000,updateTimeInMilliseconds);
    }

    private void FlightInfoUpdateTimerTick(int updateTimeInMilliseconds)
    {
        flightInfoUpdateTimer = new Timer();
        flightInfoUpdateTimer.scheduleAtFixedRate(new TimerTask()
        {
            public void run()
            {
                try
                {
                    UpdateFlightInfo();
                }
                catch(Exception e)
                {

                }

            }
        }
                ,1000,updateTimeInMilliseconds);
    }

    private  void UpdateFlightList()
    {
        listActiveFlights.removeAll();
        List<String> flights = ADSBMessageMap.getInstance().getAllActive();
        DefaultListModel model = new DefaultListModel();

        for(String s : flights)
            model.addElement(s);

        listActiveFlights.setModel(model);
    }

    private void UpdateFlightInfo()
    {
        ADSBAirbornePositionMessage msgPosition = ADSBAirbornePositionMessage.class.cast(ADSBMessageMap.getInstance().getLastMessageOfType(currentICAO, ADSBMessageMap.MsgType.positionMessage));
        ADSBAirborneVelocityMessage msgVelocity = ADSBAirborneVelocityMessage.class.cast(ADSBMessageMap.getInstance().getLastMessageOfType(currentICAO, ADSBMessageMap.MsgType.velocityMessage));
        ADSBAircraftIdentificationMessage msgId = ADSBAircraftIdentificationMessage.class.cast(ADSBMessageMap.getInstance().getLastMessageOfType(currentICAO, ADSBMessageMap.MsgType.identificationMessage));

        if(msgPosition != null)
        {
            textField1.setText(new Integer(msgPosition.getAltitude()).toString());

        }

        if(msgVelocity != null)
        {

        }

        if(msgId != null)
        {
            
        }
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


