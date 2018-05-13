package proj;

import java.util.ArrayList;
import java.util.Arrays;

public class ShapeIterator extends AbstractList{
	//Our chosen form of data storage
	private ArrayList<Shape> myShapes = new ArrayList<Shape>();
	public class Iterator extends AbstractIterator implements MyIterator{
		private int index=0;
		public void first() {
			index=0;
		}
		//Increments index
		public void next() {
			if (!isDone())
				index++;
		}
		//Returns true if iterator is done; false otherwise
		public boolean isDone() {
			if (index==myShapes.size())
				return true;
			else
				return false;
		}
		//returns current shape
		public Shape currentItem() {	
			return myShapes.get(index);
		}	
	}
	//generates a new default iterator
	public AbstractIterator createIterator() {
		return new Iterator();
	}

	//Add a new shape
	public void append(Shape newShape) {
		myShapes.add(newShape);
	}

	//remove a given shape (used for compound)
	public void remove(Shape oldShape) {
		for (int i=0;i<myShapes.size();i++){
			if (myShapes.get(i)==oldShape){
				myShapes.remove(i);
				break;
			}
		}
	}
}
