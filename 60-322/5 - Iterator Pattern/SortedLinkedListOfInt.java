package iterator;

public class SortedLinkedListOfInt extends AbstractList{
	private node startList=null; 
	private node curr; 
	private int curr_index;
	private int end;

	//Inner class used to store nodes
	public class node{
		private int item;
		private node next;
		node(int n){
			item=n;
			next=null;
		}
	}
	//The Iterator
	public class Iterator extends AbstractIterator implements MyIterator{
		//sets the end and current points
		public Iterator(int n){
			curr = startList;
			curr_index=0;
			end=n;
		}
		//Goes to first element
		public void first() {
			curr = startList; 
			curr_index=0;
		}
		public void next(){
			if (!isDone()){
				curr=curr.next;
				curr_index++;
			}
		}
		//Checks if either we reached end of iteration or end of linked list
		public boolean isDone() {
			if ((end==curr_index)||(curr.next==null))
				return true;
			else
				return false;
		}
		//Returns the int item of each node
		public Integer currentItem() {
			return curr.item;
		}
		
	}
	//Generates a new iterator
	public AbstractIterator createIterator(int numElements) {
		return new Iterator(numElements);
	}

	//Calls insert function to insert the element into the list
	public void append(int v) {
		insert(v);
	}
	public void insert(int n){
		node nde,temp; 
		//Case1: List is empty
		if (startList==null){
			startList = new node(n);
			curr=startList;
		}
		//Case2: Node inserted at start
		else if (startList.item<n){
			temp = startList;
			startList = new node(n);
			startList.next=temp;
		}
		//Case3: Node inserted in the middle or end
		else{
			nde = startList;
			//Search for insert location
			while((nde.next!=null)&&((nde.next).item>n)){
				nde=nde.next;
			}
			//Perform the insert
			temp=nde.next;
			nde.next= new node(n);
			(nde.next).next = temp; 
		}
	}

}
