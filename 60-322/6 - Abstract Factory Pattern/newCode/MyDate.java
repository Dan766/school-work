package newCode;

import java.util.StringTokenizer;

public abstract class MyDate {
	public abstract String toString();
	private int day;
	private int month;
	private int year;

	public MyDate(String inputString){
		StringTokenizer tokenizeDate = new StringTokenizer(inputString, "/");
		this.setDay(Integer.parseInt(tokenizeDate.nextToken()));
		this.setMonth(Integer.parseInt(tokenizeDate.nextToken()));
		this.setYear(Integer.parseInt(tokenizeDate.nextToken()));
	}

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}

	public int getMonth() {
		return month;
	}

	public void setMonth(int month) {
		this.month = month;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}
}
