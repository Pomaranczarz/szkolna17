package Zad5_2;

public class Undergraduate extends Adult implements University {
    @Override
    public void study() {
        System.out.println("Student studiuje");
    }

    @Override
    public void missLectures() {
        System.out.println("Student opuszcza zajęcia");
    }

    public Undergraduate(int age, String[] traits, String[] duties) {
        super(age, traits, duties);
    }
}
