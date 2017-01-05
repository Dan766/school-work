package newCode;

public abstract class DateAddress {
	private MyDate today;
	private String address;
	private String province;
	DateAddress(MyDate today, String address, String province){
		this.setToday(today);
		this.setAddress(address);
		this.setProvince(province);
	}
	public abstract String displayDateAddress();
	public MyDate getToday() {
		return today;
	}
	public void setToday(MyDate today) {
		this.today = today;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	public String getProvince() {
		return province;
	}
	public void setProvince(String province) {
		this.province = province;
	}
	
}
