package proj;

import java.awt.Color;
import java.awt.Graphics;

public abstract class Shape extends Object {
	private Coordinates referencePoint; // top left corner of the rectangle
	
	private Color color; // color of a rectangle 
	private Color originalColor;// Used to save the original color when the color changes temporarily
	
	private Coordinates lastMousePosition; 
	/* 
	 * If a rectangle has been  selected for moving, lastMousePosition gives the position where the 
	 * user has pressed the mouse.
	 */
	
	private boolean shapeSelected = false;
	/*
	 * shapeSelected = false means that the  rectangle has  been selected for 
	 * moving by pressing mouse button inside the shape.
	 */
	
	protected boolean perimeterSelected = false;
	
	public Shape(Color c, Coordinates rp){
		this.color =c;
		this.referencePoint=rp;
	}
	
	/* 				Getter
	 * 				Functions
	 */
	public Coordinates getReferencePoint(){
		return referencePoint;
	}
	public Coordinates getLastMousePosition(){
		return lastMousePosition;
	}
	public Color getColor(){
		return color;
	}
	public boolean getShapeSelected(){
		return shapeSelected;
	}
	
	/* 				Setter
	 * 				Functions
	 */
	public void setReferencePoint(Coordinates rp){
		referencePoint=rp;
	}
	public void setLastMousePosition(Coordinates lm){
		lastMousePosition=lm;
	}
	public void setShapeSelected(boolean s){
		shapeSelected = s;
	}
	
	
	//changeColor(c) modifies the color of the shape to the new color c
	public void changeColor(Color c){
		color = c ;
	}
	
	public void changeColorTemporarily(){	 
		originalColor = color; 
		color = Color.yellow ;
		perimeterSelected = true;
	}
	public boolean perimeterSelected(){
		return perimeterSelected;
	}
	public void changeColorBack(){	 
		color = originalColor; 
		perimeterSelected = false;
	}
	
	/* 
	 * Method shapeIsSelected() returns true if the user previously selected the shape by 
	 * pressing the mouse button with the cursor inside the shape.
	 */
	public boolean shapeIsSelected(){
		return shapeSelected;
	}
	/* 
	 * resetShapeSelected() simply resets the value of shapeSelected to false.
	 */
	public void resetShapeSelected(){
		shapeSelected = false;
	}
	/*
	 * savePositionWhereUserPressedMouse(int x, int y)is used to 
	 * save the position where the user Pressed the mouse button.
	 * This is useful for moving the shape.
	 */
	public void savePositionWhereUserPressedMouse(int x, int y){
		lastMousePosition = new Coordinates(x, y);
	}
	public abstract boolean shapeIsSelected(Coordinates positionOfMouse);
	public abstract boolean onThePerimeter(Coordinates mousePosition);
	abstract void moveShape(Coordinates currentPositionMouse);
	abstract double calculateArea();
	public abstract void showMe(Graphics g);
	public abstract String toString();
}
