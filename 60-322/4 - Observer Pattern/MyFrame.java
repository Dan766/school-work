package ab3;
/*
 * MyFrame object is used to take input from the user (age and name)
 * MyFrame can not be set directly as a observable object so we use a
 * intermediary object called ageNameSubject to store MyFrame's data
 */
import java.awt.FlowLayout;
import java.awt.event.*;
import java.util.* ;
import javax.swing.*;

public class MyFrame extends JFrame implements ActionListener{
	//Static reference to corresponding observable object
	private static DelegatedObservable obs;
	
	private JLabel aLabel, bLabel;
	private JTextField area1, area2;

	private Integer age = 0;
	private String name = null;

	public void setAge(Integer n)
	{
		this.age= n;
		//Notify observers that data has change and sends them the new integer value
		obs.setChanged();
		obs.notifyObservers(new Integer(n));
	}
	public void setName(String n)
	{
		this.name= n;
		//Notify observers that data has change and sends them the new String value
		obs.setChanged();
		obs.notifyObservers(new String(n));
	}
	public Integer getAge()
	{
		return age;
	}
	public String getName()
	{
		return name;
	}	
	public MyFrame(String n, int a){
		super("User Input Area");
		setLayout(new FlowLayout());
		aLabel = new JLabel("What is your name?");
		add(aLabel);
		area1  = new JTextField( 10 );
		area1.addActionListener(this);
		add(area1);
		bLabel = new JLabel("How old are you?");
		add(bLabel);
		area2  = new JTextField( 10 );
		area2.addActionListener(this);
		add(area2);	
		
		//Creates Observable object
		obs = new DelegatedObservable();
		name=n;
		age=a;
	}
	public void actionPerformed(ActionEvent e){
		Integer age;
		String name;
		if (e.getSource() == area1){
			name = area1.getText();
			area1.setText("");
			//Updates our observable
			setName(name);
		} else {			 
			age = Integer.parseInt(area2.getText());	
			area2.setText("");
			//Updates our observable
			setAge(age);
		}
	}	
	public static void main(String a[]){	
		
		//Sets up our main input frame
		MyFrame aFrame;
		aFrame = new MyFrame("", 0);
		aFrame. setSize(300, 100);
		aFrame. setVisible(true);
		
		//Tests the observer objects
		AgeObserver ageObserver;
		NameObserver nameObserver;
		
		//Creates and adds observers 
		nameObserver = new NameObserver();
		ageObserver = new AgeObserver();
		
		obs.addObserver(ageObserver);
		obs.addObserver(nameObserver);
	}

}