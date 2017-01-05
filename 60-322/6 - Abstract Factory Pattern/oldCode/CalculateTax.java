package badCode;
import java.util.Calendar;
import java.text.SimpleDateFormat;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CalculateTax extends JFrame implements ActionListener {
	
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
	
	
	public CalculateTax(){
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
	
	private double computeTaxOntario(double income){
		if (income < 5000.00){
			return 0.0;
		} else if (income < 10000.00){
			return 0.1 * income;
		} else {
			return 0.2 * income;
		} 
	}
	
	private double computeTaxQuebec(double income){
		if (income < 8000.00){
			return 0.0;
		} else if (income < 12000.00){
			return 0.15 * income;
		} else {
			return 0.25 * income;
		} 
	}
	
	private void displayDateAddress(MyDate today, String address, 
			                 String province){
		if (province. equals("Quebec")){
			outputArea.setText(today.toStringFrench() + "\n\n");
		}  else{
			outputArea.setText(today.toStringEnglish() + "\n\n");
		}
		outputArea.append(address + "\n");
		outputArea.append(province + "\n\n");
	}
	
	private void displaySalutation(String name, String gender, 
			                       String province){
		if (province. equals("Quebec")){
			if (gender.equals("male")){
			   outputArea.append("Cher Mr " + name + ",\n");
			} else{
				outputArea.append("Chere Mme/Melle " + name + ",\n");	
			}
		}  else{
			if (gender.equals("male")){
			   outputArea.append("Dear Mr " + name + ",\n");
			} else{
				outputArea.append("Dear Ms " + name + ",\n");	
			}
		}
	}
	
	private void displayBodyLetter(double taxPayable, String province){
		if (province. equals("Quebec")){
			   outputArea.append("Votre taxe est $" + taxPayable + "\n\n");
			   outputArea.append("Sincerement votre"); 
		}  else{
				outputArea.append("Your tax is $" + taxPayable + "\n\n");
				outputArea.append("Yours sincerely"); 
		}
	}
	
	private void displayLetter(String name, String gender, 
			                   String address, String province, 
			                   double income){	
		double taxPayable;
		Calendar cal;
		MyDate today;
		SimpleDateFormat sdf;
		
		if (province.equals("Quebec")){
			taxPayable = computeTaxQuebec(income);
		} else{
			taxPayable = computeTaxOntario(income);
		}
		cal = Calendar.getInstance();
		sdf = new SimpleDateFormat("dd/MM/yyyy");
		today = new MyDate(sdf.format(cal.getTime()));
		displayDateAddress(today, address, province);
		displaySalutation(name, gender, province);
		displayBodyLetter(taxPayable, province); 
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
		displayLetter(name, gender, address, province, income);
		inputName.setText("");
		inputAddress.setText("");
		inputProvince.setText("");
		inputIncome.setText("");
	}
	
	public static void main(String a[]){
		CalculateTax newFrame = new CalculateTax();
	}

}
