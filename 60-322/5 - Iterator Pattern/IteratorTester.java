package iterator;

public class IteratorTester 
{
    public static void main(String args[]) {
    	//Important point. This version will work only with 10 or fewer entries in the array elements 
		int elements[] = { 1,2,10,4,13,6,9,20,21,32,32,100,23,99};
		AbstractList myArray;
		AbstractList.AbstractIterator myIterator;
		if (elements.length<=10)
			myArray = new ArrayOfIntWithIterator();
		else
			myArray = new SortedLinkedListOfInt();
		for (int i = 0; i < elements.length; i++)
           myArray.append(elements[i]);
        myIterator = myArray.createIterator(6);
        myIterator.first();
        while (!myIterator.isDone()){
			System.out.println(myIterator.currentItem().toString() + " ");
			myIterator.next();
		}

	}
}

