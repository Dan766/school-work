package newCode;

public abstract class TaxCalculator {
	private double income; 
	TaxCalculator(double income){
		this.setIncome(income);
	}
	public abstract double taxPayable();
	public double getIncome() {
		return income;
	}
	public void setIncome(double income) {
		this.income = income;
	}
}
