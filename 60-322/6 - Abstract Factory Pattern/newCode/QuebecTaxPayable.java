package newCode;

public class QuebecTaxPayable extends TaxCalculator{
	QuebecTaxPayable(double income){
		super(income);
	}
	public double taxPayable(){
		if (getIncome() < 8000.00){
			return 0.0;
		} else if (getIncome() < 12000.00){
			return 0.15 * getIncome();
		} else {
			return 0.25 * getIncome();
		} 
	}
}
