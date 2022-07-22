package Zad5_2;

import java.util.ArrayList;
import java.util.Arrays;

public abstract class Human implements Base {
    private final int age;
    private final ArrayList<String> traits;

    @Override
    abstract public void eat();

    @Override
    abstract public void drink();

    @Override
    abstract public void sleep();

    @Override
    abstract public void wakeUp();

    public int getAge() { return age; }
    public ArrayList<String> getTraits() { return traits; }

    public Human(int age, String[] traits) {
        this.age = age;
        this.traits = new ArrayList<>( Arrays.asList(traits) );
    }

}
