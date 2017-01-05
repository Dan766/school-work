package newCode;

public class FrenchDateAddress extends DateAddress{

	FrenchDateAddress(MyDate today, String address, String province) {
		super(today, address, province);
	}

	@Override
	public String displayDateAddress() {
		String output=getToday().toString() + "\n\n";
		output+=getAddress() + "\n";
		output+="Quebec" + "\n\n";
		return output; 
		
	}

}
