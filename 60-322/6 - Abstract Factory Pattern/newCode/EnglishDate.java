package newCode;

public class EnglishDate extends MyDate{

	public EnglishDate(String inputString) {
		super(inputString);
	}

	@Override
	public String toString() {
		String monthNames[] = {"January", "February", "March", "April", "May",
                "June", "July", "August", "September", "October",
                "November", "December"};	

			return ( monthNames[getMonth()-1] + " " + getDay() +  ", " + getYear() );
	}

}
