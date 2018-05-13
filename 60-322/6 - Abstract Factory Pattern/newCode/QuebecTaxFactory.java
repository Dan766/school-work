package newCode;

import java.text.SimpleDateFormat;
import java.util.Calendar;

public class QuebecTaxFactory extends IncomeTaxCalculator{

	@Override
	public String createDateAdress(newCode.MyDate today, String address, String province) {
		return (new FrenchDateAddress(today,address,province)).displayDateAddress();
	}

	@Override
	public double calculateTax(double income) {
		return (new QuebecTaxPayable(income)).taxPayable();
	}

	@Override
	public String createLetterBody(String name, String gender, String address, String province, double income) {
		double taxPayable;
		Calendar cal;
		MyDate today;
		SimpleDateFormat sdf;
		String output = "";
		
		taxPayable = calculateTax(income);
		
		cal = Calendar.getInstance();
		sdf = new SimpleDateFormat("dd/MM/yyyy");
		today = new FrenchDate(sdf.format(cal.getTime()));
		
		output+=createDateAdress(today, address, province);
		
		output+=(new QuebecLetterBody(name,gender,address,province,income)).displayLetter(); 
		return output; 
	}
}
