package newCode;


public abstract class IncomeTaxCalculator {
	public abstract String createDateAdress(
			MyDate today, 
			String address, 
            String province);
	
	public abstract double calculateTax(
			double income);
	
	public abstract String createLetterBody(String name, String gender, String address, String province, double income);

	
}
