package newCode;

public class FrenchDate extends MyDate{

	public FrenchDate(String inputString) {
		super(inputString);
	}

	@Override
	public String toString() {
		String monthNames[] = {"janvier", "fevrier", "mars",
				"avril", "mai", "juin", "juillet", "aout", 
				"septembre", "octobre", "novembre", "decembre"};
			return ( getDay() + " " + monthNames[getMonth()-1] +  ", " + getYear() );
	}

}
