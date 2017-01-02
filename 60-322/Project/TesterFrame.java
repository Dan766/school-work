package proj;

import javax.swing.*;

import proj.AbstractList.AbstractIterator;

import java.awt.*;
import java.awt.event.*;
import java.util.Arrays;


public class TesterFrame extends JFrame{
	public static final int WIDTH = 900, HEIGHT = 500; // the width and height of the frame

	private static DelegatedObservable obs;
	private Shape currentShape;
	private int currentPhase;
	private Color currentColor = Color.black;
	private EditorPanel myPanel; 
	private JPanel shapeButtonPanel, colorChooserPanel;
	private JTextField messageArea;
	private ButtonGroup radioButtonGroupForSelectingShape, radioButtonGroupForChoosingColor;
	private JRadioButton redButton, greenButton, blueButton, blackButton;
	private JTextField inputArea;
	
	//myShape stores the class containing the array of shapes
	//myItr is used for iterating through this array of shapes
	ShapeIterator myShapes = new ShapeIterator();
	AbstractIterator myItr = myShapes.createIterator();
	
	
	/*
	 * updateShapes updates the following observers:
	 * 		a) display in showSquaresAndRectangles details about rectangles and squares
	 *      b) display in showBigCircle details about circles that have an area > 5000
	 */
	public void updateShapes(){
		obs.setChanged();
		obs.notifyObservers(myShapes);
	}
	
	
	
	/*
	 * redisplay has the following responsibilities:
	 * 		a) display in showSquaresAndRectangles details about rectangles and squares
	 *      b) display in showBigCircle details about circles that have an area > 5000
	 */
	
	public void redisplay(){
		myPanel.repaint();
		//Updates the observers
		updateShapes();
	}
	
	public void compoundSelectedShapes() {
		int numberOfShapes=0; 
		CompoundShape newShape = new CompoundShape(currentColor, null);
		for (myItr.first();!myItr.isDone();myItr.next()){
			if (myItr.currentItem().perimeterSelected()) {
				numberOfShapes++;
			}
		}
		for (int i=0;i<numberOfShapes;i++){
			for (myItr.first();!myItr.isDone();myItr.next()){
				if (myItr.currentItem().perimeterSelected()) {
					//Change each color back to original
					myItr.currentItem().changeColorBack();
					
					//add each of the elements to our compound object
					newShape.addShape(myItr.currentItem());
					
					//remove each element from the list
					myShapes.remove(myItr.currentItem());
				}
			}
		}
		
		//Append our compound object to myShapes
		myShapes.append(newShape);
		
	}
	

	private class EditorPanel extends JPanel{
		public void paintComponent(Graphics g){
			super.paintComponent(g);
			for (myItr.first();!myItr.isDone();myItr.next()){// Show all the shapes in my_shapes. 
					myItr.currentItem().showMe(g);
			}
		}
	}

	private EditorPanel buildEditorPanel(){
		EditorPanel myPanel;
		myPanel = new EditorPanel();

		myPanel.addMouseListener(new MouseAdapter(){
			/* 
			 * mousePressed is important for selecting a shape for dragging it (currentPhase = 0) and for
			 *              selecting a perimeter of a shape to define a compound shape (currentPhase = 5).
			 */
			public void mouseReleased(MouseEvent e){
				for (myItr.first();!myItr.isDone();myItr.next()){
					// when the mouse button is released reset the flags indicating that shape(s) or 
					// edge(s) has been selected and restore color since the drag operation or the modify 
					// operation is over.
					myItr.currentItem().resetShapeSelected();
				}
			}

			public void mousePressed(MouseEvent e){
				int x_value, y_value;
				Coordinates currentMousePosition;
				x_value = e.getX(); // Find the coordinates of the position where the user pressed the mouse button
				y_value = e.getY();
				currentMousePosition = new Coordinates(x_value, y_value);
				if (currentPhase == 0){
					for (myItr.first();!myItr.isDone();myItr.next()){
						/* 
						 * If a shape is selected by pressing mouse button inside the shape, 
						 * save the place where the user pressed mouse button sets the flag 
                         * denoting that the shape is selected.
						 */
						myItr.currentItem().shapeIsSelected(currentMousePosition);
					}
				}
					/* 
					 * If we are defining compound shape i.e., currentPhase == 1, we select a
					 * shape by pressing the mouse button very close to the parameter.
					 * The color of the shape is temporarily changed to yellow. 
					 */
				else if (currentPhase == 1){
					for (myItr.first();!myItr.isDone();myItr.next()){
						if (myItr.currentItem().onThePerimeter(currentMousePosition))
							myItr.currentItem().changeColorTemporarily();
					}
				}		
				redisplay();
			}   	                      
		});

		myPanel.addMouseMotionListener(new MouseMotionAdapter(){
			public void mouseDragged(MouseEvent e){				
					/* 
					 * if the mouse is dragged when currentPhase is 0, the selected shapes move 
					 * with the mouse, using method moveShape.
					 */
				for (myItr.first();!myItr.isDone();myItr.next()){ 
					// If the operation is to drag shapes
					myItr.currentItem(). shapeIsSelected();
					myItr.currentItem(). moveShape(new Coordinates(e.getX(), e.getY()));
				}			
				redisplay();   
			} 
		});

		myPanel.setBackground(Color.WHITE);
		return myPanel;
	}

	private JPanel buildShapeChooserPanel(){
		JPanel buttonPanel;
		JButton squareButton, rectangleButton, circleButton, 
		        compoundFigureButton;
        /*
         * Create each of the buttons squareButton, rectangleButton, circleButton, compoundFigureButton
         * and define the event handler for ActionEvent.
         */

		buttonPanel = new JPanel();
		compoundFigureButton = new JButton("COMPOUND");
		compoundFigureButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				if (currentPhase == 0){ // When button COMPOUND is pressed for the first time
					                    // currentPhase becomes 1 and the user can specify the shapes
					                    // (currently rectangle or circle) to be glued together
					currentPhase = 1;
					messageArea.setText("select figures and hit compound again");
					redisplay();
				} else{ // When button COMPOUND is pressed for the second time normal operation resumes again.
					    // This is currently done by setting currentPhase to 0. You have to include code to 
					    // create the compound shape.
					compoundSelectedShapes(); 
					currentPhase=0;
					redisplay();
				}		
			}
		}
		);
		buttonPanel.add(compoundFigureButton);
		squareButton = new JButton("Create SQUARE");
		squareButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
			    messageArea.setText("Square width/height?");
			    currentShape = new Square(currentColor);
			    myShapes.append(currentShape);
				redisplay();
			}
		}
		);
		buttonPanel.add(squareButton);

		rectangleButton = new JButton("Create RECTANGLE");
		rectangleButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){	
				    messageArea.setText("Rectangle width?");
				    currentShape = new Rectangle(currentColor);
				    myShapes.append(currentShape);
					redisplay();
			}
		}
		);

		buttonPanel.add(rectangleButton);

		circleButton = new JButton("Create CIRCLE");
		circleButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
					messageArea.setText("Circle Diameter?");
					currentShape = new Circle(currentColor);
					myShapes.append(currentShape);
					redisplay();
			}
		}
		);
		buttonPanel.add(circleButton);
		messageArea = new JTextField(20);
		buttonPanel.add(messageArea);
		
		inputArea = new JTextField(3);
		inputArea.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				int width, height, diameter;
				if (messageArea.getText().equals("Rectangle width?")){
					if (!(inputArea.getText().equals(""))){
						width = Integer.parseInt(inputArea.getText());
						((Rectangle) currentShape).changeWidth(width);
					}
					messageArea.setText("Rectangle height?");
					inputArea.setText("");
					redisplay();
				} else if (messageArea.getText().equals("Rectangle height?")){
					if (!(inputArea.getText().equals(""))){
						height = Integer.parseInt(inputArea.getText());
						((Rectangle) currentShape).changeHeight(height);
					}
					messageArea.setText("");
					inputArea.setText("");
					redisplay();
				} else if (messageArea.getText().equals("Circle Diameter?")){
					if (!(inputArea.getText().equals(""))){
						diameter = Integer.parseInt(inputArea.getText());
						((Circle) currentShape).changeDiameter(diameter);
					}
					messageArea.setText("");
					inputArea.setText("");
					redisplay();
				}	else if (messageArea.getText().equals("Square width/height?")){
					if (!(inputArea.getText().equals(""))){
						width = Integer.parseInt(inputArea.getText());
						((Square) currentShape).changeWidth(width);
					}
					messageArea.setText("");
					inputArea.setText("");
					redisplay();
				}
			} 
		}
		);
		buttonPanel.add(inputArea);
		return buttonPanel;
	} 


	/*
	 * buildColorChooserPanel included 3 radio buttons so that users can select red, blue or green
	 * in addition to the original black color for the newly created shape. The user can select 
	 * one of these buttons to change the color for the newly created shape.
	 * We have used a  straight-forward anonymous handler for events in each radio button.
	 */

	private JPanel buildColorChooserPanel(){
		JPanel radioButtonPanel;
		

		radioButtonPanel = new JPanel();
		blackButton = new JRadioButton("BLACK");
		blackButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				currentColor = Color.black;
			}
		}
		);
		redButton = new JRadioButton("RED");
		redButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				currentColor = Color.red;
			}
		}
		);

		greenButton = new JRadioButton("GREEN");
		greenButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				currentColor = Color.green;
			}
		}
		);

		blueButton = new JRadioButton("BLUE");
		blueButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				currentColor = Color.blue;
			}
		}
		);

		radioButtonGroupForChoosingColor = new ButtonGroup();
		radioButtonGroupForChoosingColor.add(blackButton);
		radioButtonGroupForChoosingColor.add(blueButton);
		radioButtonGroupForChoosingColor.add(greenButton);
		radioButtonGroupForChoosingColor.add(redButton);
		radioButtonPanel.add(blackButton);
		radioButtonPanel.add(blueButton);
		radioButtonPanel.add(greenButton);
		radioButtonPanel.add(redButton);
		return radioButtonPanel;
	}

	public TesterFrame(){	
		currentPhase = 0;
		myPanel = buildEditorPanel();
		shapeButtonPanel = buildShapeChooserPanel();
		colorChooserPanel = buildColorChooserPanel();

		obs = new DelegatedObservable();
		
		add(colorChooserPanel, BorderLayout.NORTH);
		add(shapeButtonPanel, BorderLayout.SOUTH);
		add(myPanel, BorderLayout.CENTER);
		setSize(WIDTH, HEIGHT);
		setVisible(true);
	}

	//Main program logic
	public static void main(String a[]){
		
		//Creates observers and attaches them to the observable
		FrameShowingBigCircles CircleObserver = new FrameShowingBigCircles();
		OutputFrame recSquareObserver = new OutputFrame();
		
		//creates input frame
		new TesterFrame();
		
		obs.addObserver(CircleObserver);
		obs.addObserver(recSquareObserver);
	}
}