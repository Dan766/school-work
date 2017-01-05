package badCode;

import java.util.StringTokenizer;

public class MyDate {
	private int day;
	private int month;
	private int year;

	public MyDate(String inputString){
		StringTokenizer tokenizeDate = new StringTokenizer(inputString, "/");
		this.day = Integer.parseInt(tokenizeDate.nextToken());
		this.month = Integer.parseInt(tokenizeDate.nextToken());
		this.year = Integer.parseInt(tokenizeDate.nextToken());
	}
	
	
	
	
	
	/* 
	 * Method toString return a string describing the date in the following format:
	 * a) the month name, a space, followed by 
	 * b) the date, a space, a quote, followed by
	 * c) the last two digits of the year  
	 */

	public String toStringEnglish(){
		String monthNames[] = {"January", "February", "March", "April", "May",
                "June", "July", "August", "September", "October",
                "November", "December"};	

			return ( monthNames[month-1] + " " + day +  ", " + year );
		
	}
	public String toStringFrench(){	
		String monthNames[] = {"janvier", "fevrier", "mars",
				"avril", "mai", "juin", "juillet", "aout", 
				"septembre", "octobre", "novembre", "decembre"};
			return ( day + " " + monthNames[month-1] +  ", " + year );
		
	}
}