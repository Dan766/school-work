package proj;

import java.awt.Color;
import java.awt.Graphics;

public class Square extends Shape{
	Rectangle square;
	// Constructor creates a black rectangle with size 50 X 50 with upper left point at (200, 200)
	public Square(Color c){
		super(c, new Coordinates(200, 200));
		square = new Rectangle(c);
	}

	//Delegates all methods to the rectangle object
	public boolean onThePerimeter(Coordinates mousePosition){
		return square.onThePerimeter(mousePosition);
	}
	void moveShape(Coordinates currentPositionMouse){	
		square.moveShape(currentPositionMouse);
	}
	public boolean shapeIsSelected(Coordinates positionOfMouse){ 
		return square.shapeIsSelected(positionOfMouse);
	}
	double calculateArea(){ 
		return square.calculateArea();
	}
	public void showMe(Graphics g){
		square.showMe(g);
	}
	public void changeWidth(int newWidth){
		square.changeHeight(newWidth);
		square.changeWidth(newWidth);
	}
	public void changeHeight(int newHeight){
		square.changeHeight(newHeight);
		square.changeWidth(newHeight);
	}
	public Color getColor(){
		return square.getColor();
	}
	public boolean getShapeSelected(){
		return square.getShapeSelected();
	}
	public void setReferencePoint(Coordinates rp){
		square.setReferencePoint( rp);
	}
	public void setLastMousePosition(Coordinates lm){
		square.setLastMousePosition(lm);
	}
	public void setShapeSelected(boolean s){
		square.setShapeSelected(s);
	}
	public Coordinates getReferencePoint(){
		return square.getReferencePoint();
	}
	
	//changeColor(c) modifies the color of the shape to the new color c
	public void changeColor(Color c){
		square.changeColor( c);
	}
	
	public void changeColorTemporarily(){	 
		square.changeColorTemporarily();
	}
	public boolean perimeterSelected(){
		return square.perimeterSelected();
	}
	public void changeColorBack(){	 
		square.changeColorBack();
	}
	
	/* 
	 * Method shapeIsSelected() returns true if the user previously selected the shape by 
	 * pressing the mouse button with the cursor inside the shape.
	 */
	public boolean shapeIsSelected(){
		return square.shapeIsSelected();
	}
	/* 
	 * resetShapeSelected() simply resets the value of shapeSelected to false.
	 */
	public void resetShapeSelected(){
		square.resetShapeSelected();
	}
	public String toString(){
		return ("Square with reference point " + square.getReferencePoint() + " having width "
				+ square.getWidth() + " and height " + square.getHeight() + "\n");
	}
	
}
