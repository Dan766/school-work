package ab3;

/*
 * ageObserver is the observer object which outputs each int entered into 
 * the observable MyFrame object
 */

import java.util.Observable;
import java.util.Observer;

public class AgeObserver implements Observer {
	private Integer age;
	private OutputFrame ageFrame;
	public AgeObserver(){
		this.age = 0;
		ageFrame = new OutputFrame("age");
		ageFrame. setSize(275,200);
		ageFrame. setVisible(true);
	}
	//outputs age to the ageFrame when an integer value is detected
	public void update(Observable o, Object arg) {
		if (arg instanceof Integer) { 
			age = ((Integer)arg).intValue();
			ageFrame.insert(age);
		}
	}

}
