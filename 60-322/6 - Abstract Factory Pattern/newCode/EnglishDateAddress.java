package newCode;


public class EnglishDateAddress extends DateAddress{
	EnglishDateAddress(MyDate today, String address, String province){
		super(today,address,province);
	}

	@Override
	public String displayDateAddress() {
		String output = (getToday()).toString() + "\n\n";
		output+=getAddress() + "\n";
		output+="Ontario" + "\n\n";
		return output; 
	}
}
