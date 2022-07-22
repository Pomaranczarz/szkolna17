package Zad5_2;

public class Pensioner extends Adult implements Retirement {
    @Override
    public void getPension() { System.out.println("Emeryt odebrał emeryturę"); }
    @Override
    public void goToDoctor() { System.out.println("Emeryt odwiedził doktora"); }

    public Pensioner(int age, String[] traits, String[] duties) {
        super(age, traits, duties);
    }
}
