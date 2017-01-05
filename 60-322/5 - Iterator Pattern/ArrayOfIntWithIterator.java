package iterator;



public class ArrayOfIntWithIterator extends AbstractList{
	  private Integer table[];
	  private int numElements = 0;


	  public ArrayOfIntWithIterator(){
		  table = new Integer[10];
	  }

	  public class Iterator extends AbstractIterator implements MyIterator{
	       private Integer result[];
	       private int currentElement;
	       private int numElementsinResult = 0; // Stores the number of elements in result
	       private boolean endOfTable;

	       private void insertSort(Integer newElement, Integer result[]){
		   	  Integer tempValue1, tempValue2;
		   	  int positionOfNewElement = 0;
		   	  boolean flag = true; // flag is true as long as the position to insert newElement in result
		   	                // has not been determined
		   	  if (numElementsinResult == 0) {
		   		  result[numElementsinResult] = newElement;
		   		  numElementsinResult =  1;
		   	  }
		   	  else {
		   		  for (int i = 0; (i < numElementsinResult) && flag; i++){
		   			  if (result[i].intValue() < newElement.intValue()){
		   				  positionOfNewElement = i;
		   				  flag = false;
		   			  }
		   		  }

		   		  if (!flag){// position for new element has been determined
		   			  tempValue1 = result[positionOfNewElement];
		   			  result[positionOfNewElement] = newElement;
		   			  for (int j = positionOfNewElement + 1 ; j < numElementsinResult; j++){
		   				  tempValue2 = result[j];
		   				  result[j] = tempValue1;
		   				  tempValue1 = tempValue2;
		   			  }
		   			  if (numElementsinResult < result.length){ // Save the last element if there is space in result
		   				  result[numElementsinResult] = tempValue1;
		   				  numElementsinResult ++;
		   			  }
		   		  }
		   		  else if (numElementsinResult < result.length){// newElement is larger than the last element in result.
		   			  result[numElementsinResult] = newElement;
		   			  numElementsinResult ++;
		   		  }
		   	  }
	       }

	       public Iterator(int n){
			   result = new Integer[n]; // result stores the array to be returned

			   for (int i = 0; i < numElements; i++){
				   insertSort(table[i], result);
			   }
	       }

	       public void first(){
			   currentElement = 0;
			   if (numElementsinResult > 0) endOfTable = false;
			   else endOfTable = true;
	       }

	       public void next(){
			   if (currentElement < numElementsinResult - 1)
			       currentElement ++;
	              else endOfTable = true;
	       }

	       public boolean isDone(){
	          return endOfTable;
	       }

	       public Integer currentItem(){
			   return result[currentElement];
	       }

	  }
	  public AbstractIterator createIterator(int numElements){
	        return new Iterator(numElements);
}
	  public void append(int v){ // Inserts new int value into the next available cell in array
	     table[numElements] = new Integer(v);
	     numElements++;
	  }
	}
