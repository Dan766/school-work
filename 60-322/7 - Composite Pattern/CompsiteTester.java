public class CompsiteTester {
	// This is the kind of tester you may use
	// the actual code will depend on your design
	// The code has a number of errors because many classes (MyStore, PurchasedPart, AssembledPart) are missing
	public static void main(String a[]){
		MyStore myStore = new MyStore(); // Assume the class containing all the parts is called MyStore 
		String listParts[] = {"P1", "P2", "P3", "P4", "P5"}; // a list of all the part numbers
		//we have two kinds of parts - purchased parts or assembled parts.
		//A purchased part has a part number and a purchase price.
		//An assembled part includes a part number  and assembly cost.

		myStore.add(new PurchasedPart("P1", 10.00));  // PurchasedPart is a part bought off the shelf
		// method add includes a new part (purchased on assembled) to my inventory
		// part "P1" is purchased from the market and costs $10.00

		myStore.add(new PurchasedPart("P2", 20.00)); 
		// part "P2" is purchased from the market and costs $20.00

		myStore.add(new AssembledPart("P3", 10.00)); // 
		//part # "P3" is assembled in the store 
		// and the cost of assembly is $10.00
		myStore.includesComponent("P3", "P1");// Part "P3" has components "P1" and "P2"
		myStore.includesComponent("P3", "P2");

		myStore.add(new AssembledPart("P4", 20.00));
		//part # "P4" is assembled in the store 
		// and the cost of assembly is $20.00
		myStore.includesComponent("P4", "P3");// Part "P4" has components "P3" and "P2"
		myStore.includesComponent("P4", "P2");

		myStore.add(new AssembledPart("P5", 30.00));
		//part # "P5" is assembled in the store 
		// and the cost of assembly is $30.00
		myStore.includesComponent("P5", "P4");// Part "P5" has components "P4", "P3" and "P1"
		myStore.includesComponent("P5", "P3");
		myStore.includesComponent("P5", "P1");

		for (String partNo:listParts){
			System.out.println("Cost of " + partNo + " is $" + myStore.findCost(partNo));
			System.out.println("Part list for "  + partNo + " is " + myStore.findPartList(partNo).toString());
		}
	}
}