package proj;

import javax.swing.*;

import java.util.Observable;
import java.util.Observer;

/*
 * OutputFrame is a observer used to display a list of all squares
 * 	generated from the TesterFrame 
 */
import javax.swing.event.*;

import proj.AbstractList.AbstractIterator;
public class OutputFrame extends JFrame implements Observer{
	final int WIDTH = 400, HEIGHT = 300;
	private JTextArea outputArea;
	public OutputFrame(){
		super("Rectangles");
		outputArea = new JTextArea(20, 30);
		add(outputArea);
		setSize(WIDTH, HEIGHT);
		setVisible(true);
	}
	
	//Sets the text we are to output 
	public void displayResult(String s){
		outputArea.setText(s);
	}
	
	//If shape array has been updated, we call displayResult to re-display the list of rectangles
	public void update(Observable o, Object arg) {
		String outputString1="";
		if (arg instanceof AbstractList){
			AbstractList myShapes = (ShapeIterator)arg;
			AbstractList.AbstractIterator myItr = myShapes.createIterator();
			for (myItr.first();!myItr.isDone();myItr.next()){
				if ( (myItr.currentItem() instanceof Rectangle) || (myItr.currentItem() instanceof Square) )
					outputString1 += (myItr.currentItem().toString());
			}
			displayResult(outputString1);
		}
	}
}


