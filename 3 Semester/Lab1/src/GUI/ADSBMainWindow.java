package GUI;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Johannes on 23.11.2015.
 */
public class ADSBMainWindow extends  JFrame
{
    private JTree treeFlights;
    private JButton button1;
    private JPanel contentPanel;

    public ADSBMainWindow()
    {
        super("ADSB Main Window");
        setContentPane(contentPanel);
        setSize(800,600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
