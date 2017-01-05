package ab3;
/*
 * NameObserver is the observer object which outputs each String entered into 
 * the observable MyFrame object
 */ 

import java.util.Observable;
import java.util.Observer;

public class NameObserver implements Observer{
	private String name;
	private OutputFrame nameFrame;
	public NameObserver(){
		this.name = null;
		nameFrame = new OutputFrame("name");
		nameFrame. setSize(275,200);
		nameFrame. setVisible(true);
	}
	//outputs name to the nameFrame when an integer value is detected
	public void update(Observable o, Object arg) {
		if (arg instanceof String) { 
			name = ((String)arg).toString();
			nameFrame.insert(name);
		}
	}

}
