package Zad5_2;

public class Child extends Human {
    @Override
    public void eat() { System.out.println("Dziecko zjadło"); }
    @Override
    public void drink() { System.out.println("Dziecko wypiło"); }
    @Override
    public void sleep() { System.out.println("Dziecko śpi"); }
    @Override
    public void wakeUp() { System.out.println("Dziecko się obudziło"); }

    public void play() { System.out.println("Dziecko się bawi"); }

    public Child(int age, String[] traits) {
        super(age, traits);
    }
}
