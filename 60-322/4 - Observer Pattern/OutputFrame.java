package ab3;

/*
 * No modifications were made to this outputFrame class
 */
import javax.swing.*;
import java.awt.*;

public class OutputFrame extends JFrame {
	private JLabel aLabel;
	private JTextArea myArea;
	public OutputFrame(String s){
		super(s);
		setLayout(new FlowLayout());
		aLabel = new JLabel("The " + s + "s are as follows:");
		add(aLabel);
		myArea = new JTextArea(10, 20);
		add(myArea);

	}

	public void insert(Object o){
		myArea.append(o.toString() + "\n");
	}
}