import java.util.ArrayList;

public abstract class MyStore {
	public ArrayList<MyStore> parts = new ArrayList<MyStore>();
	public class part{
		private String name;
		private double price;
		part(String name, double price){
			ArrayList<part> leafs = new ArrayList<part>();
			this.name=name;
			this.price=price;
		}
		
	}
	public abstract void includesComponent(String part, String comp);

	public String findCost(String partNo) {
		return null;
	}

	public Object findPartList(String partNo) {
		return null;
	}

	public void add(PurchasedPart purchasedPart) {
		parts.add(purchasedPart); 
	}

}
