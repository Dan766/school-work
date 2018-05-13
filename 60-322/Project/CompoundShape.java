package proj;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

//Class compounds two shapes into same object
public class CompoundShape extends Shape{
	//Objects in the compound
	ArrayList<Shape> myShapes;
	public CompoundShape(Color c, Coordinates rp) {
		super(c, rp);
		myShapes = new ArrayList<Shape>();
	}

	//Adds a new shape to the compound object
	public void addShape(Shape newShape){
		myShapes.add(newShape);
	}
	
	//Sets shapeIsSelected for all shapes in compound 
	public boolean shapeIsSelected(Coordinates positionOfMouse) {
		for (int i=0;i<myShapes.size();i++){
			if (myShapes.get(i).shapeIsSelected(positionOfMouse)){
				//set all to shape selected and last mouse pos
				for (int r=0;r<myShapes.size();r++){
					myShapes.get(r).setShapeSelected(true);
					myShapes.get(r).setLastMousePosition(positionOfMouse);
				}
				setLastMousePosition(positionOfMouse); 
				return true;
			}
		}
		return false;
	}
	
	//Sets setLastMousePosition for all shapes in compound 
	public void setLastMousePosition(Coordinates positionOfMouse){
		for (int i=0;i<myShapes.size();i++){
			myShapes.get(i).setLastMousePosition(positionOfMouse);
		}
	}

	//if one shape is selected in compound, the compound is all selected
	public boolean onThePerimeter(Coordinates mousePosition) {
		for (int i=0;i<myShapes.size();i++){
			if (myShapes.get(i).onThePerimeter(mousePosition)){
				return true;
			}
		}
		return false;
	}
	//if one shape is selected in compound, the compound is all selected
	public boolean perimeterSelected(){
		for (int i=0;i<myShapes.size();i++){
			if (myShapes.get(i).perimeterSelected()){
				return true;
			}
		}
		return false;
	}
	//if one shape is selected in compound, the compound is all selected
	public boolean getShapeSelected(){
		for (int i=0;i<myShapes.size();i++){
			if (myShapes.get(i).getShapeSelected()){
				return true;
			}
		}
		return false;
	}
	//Sets setShapeSelected for all shapes in compound 
	public void setShapeSelected(boolean s){
		super.setShapeSelected(s);
		for (int i=0;i<myShapes.size();i++){
			myShapes.get(i).setShapeSelected(s);
		}
	}
	//Sets changeColorTemporarily for all shapes in compound 
	public void changeColorTemporarily(){	
		for (int i=0;i<myShapes.size();i++){
			myShapes.get(i).changeColorTemporarily();
		}
	}
	//Moves all the shapes in compound 
	void moveShape(Coordinates currentPositionMouse) {
		Shape s;
		for (int i=0;i<myShapes.size();i++){
			s=myShapes.get(i);
			s.moveShape(currentPositionMouse); //urrentPositionMouse);
		}
	}
	//Sets changeColorBack for all shapes in compound 
	public void changeColorBack(){	 
		for (int i=0;i<myShapes.size();i++){
			myShapes.get(i).changeColorBack();
		}
	}
	//gets area for all shapes in compound 
	double calculateArea() {
		double area = 0;
		for (int i=0;i<myShapes.size();i++){
			area += myShapes.get(i).calculateArea();
		}
		return area;
	}
	//Sets showme for all shapes in compound 
	public void showMe(Graphics g) {
		for (int i=0;i<myShapes.size();i++){
			myShapes.get(i).showMe(g);
		}
	}

	public String toString() {
		String text = "";
		for (int i=0;i<myShapes.size();i++){
			text += myShapes.get(i).toString();
		}
		return text;
	}
}
