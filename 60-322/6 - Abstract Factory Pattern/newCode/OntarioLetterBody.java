package newCode;

import java.text.SimpleDateFormat;
import java.util.Calendar;


public class OntarioLetterBody extends LetterBody{

	OntarioLetterBody(String name, String gender, String address, String province, double income) {
		super(name, gender, address, province, income);
	}
	public String displayLetter() {
		String output=""; 
		if (getGender().equals("male")){
			   output+="Dear Mr " + getName() + ",\n";
			} else{
				output+="Dear Ms " + getName() + ",\n";	
			}
		
		output+="Your tax is $" + (new OntarioTaxPayable(getIncome())).taxPayable() + "\n\n";
		output+="Yours sincerely"; 
		return output; 
	}

}
