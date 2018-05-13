package proj;

public abstract class AbstractList {
	public abstract AbstractIterator createIterator();
	public abstract void append(Shape newShape);
	public abstract void remove(Shape oldShape);
	public abstract class AbstractIterator implements MyIterator{
	}
}
