package newCode;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Main extends JFrame implements ActionListener {
	
	public IncomeTaxCalculator tax; 
	
	private JLabel promptName;
	private JLabel promptProvince;
	private JLabel promptAddress;
	private JLabel promptIncome;
	private JTextField inputName;
	private JTextField inputProvince;
	private JTextField inputAddress;
	private JTextArea outputArea;
	private JTextField inputIncome;
	
	private JRadioButton maleButton;
	private JRadioButton femaleButton;
	String gender;
	private ActionListener myActionHandler;
	
	public Main(){
		super("Calculate Tax");
		setLayout(new FlowLayout());
		/* myActionHandler handles the event of selecting a radio button */
		myActionHandler = new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				gender = ((JRadioButton) e.getSource()).getText();
			}
		};
		
	    promptName = new JLabel("Enter Name");
	    add(promptName);	    
	    inputName = new JTextField(20);
	    add(inputName);
	    promptAddress = new JLabel("Enter Address");
	    add(promptAddress);
	    inputAddress = new JTextField(20);
	    add(inputAddress);
	    promptProvince = new JLabel("Enter Province");  
	    add(promptProvince); 
	    inputProvince = new JTextField(20);
	    add(inputProvince);
	    promptIncome = new JLabel("Enter Income"); 
	    add(promptIncome);
	    inputIncome = new JTextField(20);
	    add(inputIncome);
	    inputIncome.addActionListener(this);
	    outputArea = new JTextArea(20, 30);
	    add(outputArea);
	    maleButton = new JRadioButton("male", false);
	    femaleButton = new JRadioButton("female", false);
	    add(maleButton);
	    add(femaleButton);
	    maleButton.addActionListener(myActionHandler);
	    femaleButton.addActionListener(myActionHandler);
	    setSize(400,550);
		setVisible(true);
	}
	

	public void actionPerformed(ActionEvent evt){
		String province;
		double income;
		String name;
		String address;
		name = inputName.getText();
		address = inputAddress.getText();
		province = inputProvince.getText();
		income = Double.parseDouble(inputIncome.getText());
		
		if (province.toLowerCase().equals("on")||province.toLowerCase().equals("ontario"))
			tax = new OntarioTaxFactory();
		else
			tax = new QuebecTaxFactory();
		System.out.println(province+" "+income); //name+" "+gender+" "+address+" "+
		outputArea.append(tax.createLetterBody(name, gender, address, province, income));
		inputName.setText("");
		inputAddress.setText("");
		inputProvince.setText("");
		inputIncome.setText("");
	}
	
	public static void main(String a[]){
		Main newFrame = new Main();
	}


}
