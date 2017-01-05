package newCode;

public class QuebecLetterBody extends LetterBody{

	QuebecLetterBody(String name, String gender, String address, String province, double income) {
		super(name, gender, address, province, income);
	}

	@Override
	public String displayLetter() {
		String output = ""; 
		if (getGender().equals("male")){
			   output+="Cher Mr " + getName() + ",\n";
			} else{
				output+="Chere Mme/Melle " + getName() + ",\n";	
			}
		output+="Votre taxe est $" + (new QuebecTaxPayable(getIncome())).taxPayable() + "\n\n";
		output+="Sincerement votre"; 
		return output; 
	}

}
