package iterator;

import java.util.NoSuchElementException;

import iterator.AbstractList.AbstractIterator;
import iterator.ArrayOfIntWithIterator.Iterator;

public class SortedLinkedListOfInt extends AbstractList{
	private Node startList;
	private Node current;
	private Node previous;
	private class Node{
		public int item;
		public Node next;
		Node (int n){
			item = n;
			next = null;
		}
	}
	public class Iterator extends AbstractIterator implements MyIterator{
		public Iterator(){
			startList=null;
			current = startList;
			previous = null;
		}
		@Override
		public void first() {
			current=startList;
		}
		@Override
		public void next() {
			if (current.next==null)
				throw new NoSuchElementException();  
			else {
				previous = current; 
				current=current.next; 
			}
		}
		@Override
		public boolean isDone() {
			if (current.next==null)
				return true;
			return false; 
		}
		@Override
		public Integer currentItem() {
			// TODO Auto-generated method stub
			return current.item;
		}	
	}
	public void insert (int v){
		Node addN = new Node(v);
		if (current==startList){
			startList=new Node(v);
			current = startList;
		}
		else if (startList.item>v){
			while ((current.item>v)&&(current.next!=null)){
				current=current.next;
			}
			previous = current;
			current = current.next;
			previous.next = addN;
			addN.next = current;
			
			current = addN;
		}
	}
	SortedLinkedListOfInt
	public AbstractIterator createIterator(int numElements) {
		return new Iterator();
	}

	@Override
	public void append(int v) {
		insert(v);
	}

	
}
