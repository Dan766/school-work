package newCode;

public class OntarioTaxPayable extends TaxCalculator{
	OntarioTaxPayable(double income){
		super(income);
	}
	public double taxPayable(){
		if (getIncome() < 5000.00){
			return 0.0;
		} else if (getIncome() < 10000.00){
			return 0.1 * getIncome();
		} else {
			return 0.2 * getIncome();
		} 
	}
}
