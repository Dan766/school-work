package iterator;

public class IteratorTester 
{
    public static void main(String args[]) {
    	//Important point. This version will work only with 10 or fewer entries in the array elements 
		int elements[] = { 5, 4, 2, 12, 7, 8, 6, 15, 1,4};
		AbstractList myArray;
			
		AbstractList.AbstractIterator myIterator;
		myArray = new ArrayOfIntWithIterator();
		for (int i = 0; i < elements.length; i++)
           myArray.append(elements[i]);
        myIterator = myArray.createIterator(5);
        myIterator.first();
        while (!myIterator.isDone()){
			System.out.println(myIterator.currentItem().toString() + "\n");
			myIterator.next();
		}

	}
}

