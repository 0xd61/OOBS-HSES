package GUI;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Johannes on 23.11.2015.
 */
public class ADSBMainWindow extends  JFrame
{
    private JTree treeFlights;
    private JButton buttonUpdate;
    private JPanel contentPanel;

    public ADSBMainWindow()
    {
        super("ADSB Main Window");
        setContentPane(contentPanel);
        setSize(800,600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        buttonUpdate.addActionListener(new ButtonUpdate_Clicked());

    }

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
}
