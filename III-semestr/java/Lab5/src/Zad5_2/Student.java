package Zad5_2;

public class Student extends Child implements School {
    @Override
    public void study() {
        System.out.println("Uczeń się uczy");
    }

    @Override
    public void doHomework() {
        System.out.println("Uczeń odrabia pracę domową");
    }

    public Student(int age, String[] traits) {
        super(age, traits);
    }
}
