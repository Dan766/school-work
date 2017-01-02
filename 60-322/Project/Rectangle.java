package proj;

import java.awt.*;
/*
 * Written by Subir Bandyopadhyay Sept 1, 2012
 * Class Rectangle represents a rectangle. 
 * 
 * Properties of class Rectangle
 * referencePoint - where is the rectangle located
 * size  - the height and the width of the rectangle
 * lastMousePosition - the last position where the mouse was pressed, 
 * 						useful when moving the rectangle
 * colorRectangle - color of the rectangle
 * shapeSelected - a boolean variable which is true if the rectangle is 
 * 					selected for moving 
 * 
 * Properties of class Rectangle (See below for more details)
 * onAnEdge - returns true if mouse is pressed very close to one of the edges
 * changeColor - modify the color of the rectangle
 * changeShape - modify the width or the height of the rectangle
 * moveShape - move the rectangle by dragging the mouse 
 * shapeIsSelected - mark a rectangle as "selected" by pressing the mouse button inside the rectangle
 * resetShapeSelected - reset the shapeSelected flag
 * calculateArea - determine the area of the rectangle
 * showMe - display the rectangle inside the frame
 * toString - return a string describing the rectangle.
 * savePositionWhereUserPressedMouse - useful when dragging the shape
 * 
 */


public class Rectangle extends Shape{

	private int height, width;  // height and width of rectangle

	// Constructor creates a black rectangle with size 50 X 50 with upper left point at (200, 200)
	public Rectangle(Color c){
		super(c, new Coordinates(200, 200));
		height = 50;
		width = 50;
	}
	/*
	 * Method onThePerimeter checks if the user pressed the mouse button on the perimeter. 
	 * If so, it returns true; otherwise it return false.
	 */
	public boolean onThePerimeter(Coordinates mousePosition){
		int xWhereMousePressed, yWhereMousePressed;

		xWhereMousePressed = mousePosition.getX();
		yWhereMousePressed = mousePosition.getY();

		/*
		 * If the position where the user pressed the mouse button is within 5 pixels of 
		 * any side of the rectangle, the method will return true;
		 * Otherwise, it will return false.
		 */
		if (((xWhereMousePressed >= this.getReferencePoint().getX() - 5) &&
				(xWhereMousePressed <= (this.getReferencePoint().getX() + width + 5)) &&
				(yWhereMousePressed >= this.getReferencePoint().getY() - 5) &&
				(yWhereMousePressed <= (this.getReferencePoint().getY() + 5)))) return true;// top edge is edge # 0

				if (((xWhereMousePressed >= this.getReferencePoint().getX() - 5) &&
						(xWhereMousePressed <= (this.getReferencePoint().getX() + 5)) &&
						(yWhereMousePressed >= this.getReferencePoint().getY() - 5) &&
						(yWhereMousePressed <= (this.getReferencePoint().getY() + height + 5)))) return true;// left edge is edge # 1

				if (((xWhereMousePressed >= this.getReferencePoint().getX() - 5) &&
						(xWhereMousePressed <= (this.getReferencePoint().getX() + width + 5)) &&
						(yWhereMousePressed >= this.getReferencePoint().getY() + height - 5) &&
						(yWhereMousePressed <= (this.getReferencePoint().getY()+ height + 5)))) return true;//bottom edge-edge # 2

				if (((xWhereMousePressed >= this.getReferencePoint().getX() + width - 5) &&
						(xWhereMousePressed <= (this.getReferencePoint().getX() + width + 5)) &&
						(yWhereMousePressed >= this.getReferencePoint().getY() - 5) &&
						(yWhereMousePressed <= (this.getReferencePoint().getY() + height + 5)))) return true;// right edge-edge # 3

				return false;
	}
	
	public int getWidth(){
		return this.width;
	}
	public int getHeight(){
		return this.height;
	}
	public void changeWidth(int newWidth){
		width = newWidth;
	}
	public void changeHeight(int newHeight){
		height = newHeight;
	}
	
	/*
	 * Method moveShape(currentPositionMouse) allows the user to drag the rectangle by dragging the mouse
	 * button. The shape is first selected by pressing the mouse button with the cursor inside the shape.
	 * Then, if the user drags the mouse, the shape should move with the mouse.
	 * Moving a rectangle simply means modifying the reference point (upper left corner point) so that
	 * rectangle moves with the mouse position.
	 * The idea is that if the x and the y coordinate of the position of the mouse is moved by specified
	 * amounts,the reference point must change by exactly the same amount.
	 */
	void moveShape(Coordinates currentPositionMouse){	      
		if (this.getShapeSelected()) {
		// If a shape is selected for a move operation, change the reference point 
			// as the mouse is being dragged.
			this.getReferencePoint().setX(this.getReferencePoint().getX() + 
					currentPositionMouse.getX() -
					this.getLastMousePosition().getX());
			this.getReferencePoint().setY(this.getReferencePoint().getY() +
					currentPositionMouse.getY() -
					this.getLastMousePosition().getY());
			this.setLastMousePosition(currentPositionMouse);
		}
	}
	
	/*
	 * Method shapeIsSelected(positionOfMouse) checks if the position of the mouse where the user
	 * pressed the left mouse button is within the shape (at least 5 pixels away from the perimeter.
	 * If so, the flag shapeSelected is set and the method returns true.
	 * Otherwise, the flag shapeSelected is reset and the method returns false.
	 */
	public boolean shapeIsSelected(Coordinates positionOfMouse){ 
		// Check if the user pressed the mouse button inside the shape
		int x, y;
		x = positionOfMouse.getX();
		y = positionOfMouse.getY();
		if ((x >= this.getReferencePoint().getX() + 5) &&
				(x <= this.getReferencePoint().getX() + width - 5) &&
				(y >= this.getReferencePoint().getY() + 5) &&
				(y <= this.getReferencePoint().getY() + height - 5)) {
			this.setShapeSelected(true);
			this.setLastMousePosition(positionOfMouse);
			return true;
		}else {
			this.setShapeSelected(false);
			return false;
		}
	} 
	
	/*
	 * calculateArea() returns the area of the rectangle
	 */
	double calculateArea(){ 
		return (width * height);
	}
	
	/*
	 * showMe(g) displays the rectangle using the Graphic object g.
	 * It sets the color to be used, and draws the rectangle using the specified 
	 * reference point, the width and the height.
	 */
	public void showMe(Graphics g){
		g.setColor(this.getColor());
		g.drawRect(this.getReferencePoint().getX(), // Draw a rectangle with the specified 
				// corner point
				this.getReferencePoint().getY(),  // width and height
				width,
				height);
	}
	
	/* 
	 * toString() returns the description of the rectangle - the color, 
	 * the reference point and the size.
	 */
	public String toString(){
		return ("Rectangle with reference point " + this.getReferencePoint() + " having width "
				+ width + " and height " + height + "\n");
	}

}


