package proj;

import java.util.Observable;

//Delegates the observable methods to Observable
public class DelegatedObservable extends Observable{
	
	public void clearChanged() {
		super.clearChanged();
		}
	public void setChanged() {
		super.setChanged();
	}
	
}
