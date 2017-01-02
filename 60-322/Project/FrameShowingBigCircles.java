package proj;
import java.awt.*;
import java.util.Observable;
import java.util.Observer;

/*
 * Observer used to display all Big Circles generated in testerFrame
 */

import javax.swing.*;

import proj.AbstractList.AbstractIterator;
public class FrameShowingBigCircles extends JFrame implements Observer{
	AbstractList myShapes = new ShapeIterator();
	AbstractList.AbstractIterator myItr;
	//showCircles updates Shapes array and count and outputs to display
	public  void showCircles(AbstractList arg1){
		repaint();
	}
	
	public void paint(Graphics g){
		Circle currentCircle;
		super.paint(g);
		myItr = myShapes.createIterator();
		for (myItr.first();!myItr.isDone();myItr.next()){
			if (myItr.currentItem() instanceof Circle){
				currentCircle = (Circle) myItr.currentItem();
				if (currentCircle.calculateArea() >= 5000.00){
					currentCircle.showMe(g);
				}			
			}
		}	
	}
	
	public FrameShowingBigCircles(){
		super("Big Circles");
		setSize(TesterFrame.WIDTH, TesterFrame.HEIGHT); 
		setVisible(true);    
	}
	//If shape array has been updated, we call showCircles to re-display circles
	public void update(Observable arg0, Object arg1) {
		if (arg1 instanceof AbstractList){
			myShapes = (ShapeIterator) arg1;
			showCircles((AbstractList) arg1);
		}
	}
}