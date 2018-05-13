package newCode;

import java.text.SimpleDateFormat;
import java.util.Calendar;

public class OntarioTaxFactory extends IncomeTaxCalculator{

	@Override
	public double calculateTax(double income) {
		return (new OntarioTaxPayable(income)).taxPayable();
	}

	public String createLetterBody(String name,String gender,String address,String province, double income){
		double taxPayable;
		Calendar cal;
		MyDate today;
		SimpleDateFormat sdf;
		String output = "";
		
		taxPayable = calculateTax(income);
		
		cal = Calendar.getInstance();
		sdf = new SimpleDateFormat("dd/MM/yyyy");
		today = new EnglishDate(sdf.format(cal.getTime()));
		
		output+=createDateAdress(today, address, province);
		
		output+=(new OntarioLetterBody(name,gender,address,province,income)).displayLetter(); 
		return output; 
	}

	public String createDateAdress(MyDate today, String address, String province) {
		return (new EnglishDateAddress(today,address,province)).displayDateAddress();
	}


}
