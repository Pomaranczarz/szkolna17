package Zad5_2;

import java.util.ArrayList;
import java.util.Arrays;

public class Adult extends Human {
    ArrayList<String> duties;

    @Override
    public void eat() {
        System.out.println("Dorosły zjadł");
    }
    @Override
    public void drink() {
        System.out.println("Dorosły wypił");
    }
    @Override
    public void sleep() { System.out.println("Dorosły śpi"); }
    @Override
    public void wakeUp() { System.out.println("Dorosły wstał"); }

    public void play() {
        System.out.println("Dorosły się bawi");
    }

    public void work() {
        System.out.println("Dorosły pracuje");
    }

    public ArrayList<String> getDuties() { return duties; }

    public Adult(int age, String[] traits, String[] duties) {
        super(age, traits);
        this.duties = new ArrayList<>(Arrays.asList(duties) );
    }
}
