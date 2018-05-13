package newCode;

public abstract class LetterBody {
	private double taxPayable;
	private String province;
	private String gender;
	private String name; 
	private double income;
	private String address;
	LetterBody(String name, String gender, 
            String address, String province, 
            double income){
		this.setTaxPayable(taxPayable);
		this.setGender(gender);
		this.setName(name); 
		this.setIncome(income);
		this.setAddress(address); 
		this.setProvince(province);
	}
	public abstract String displayLetter(); 
	public String getProvince() {
		return province;
	}
	public void setProvince(String province) {
		this.province = province;
	}
	public double getTaxPayable() {
		return taxPayable;
	}
	public void setTaxPayable(double taxPayable) {
		this.taxPayable = taxPayable;
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	public double getIncome() {
		return income;
	}
	public void setIncome(double income) {
		this.income = income;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
}
