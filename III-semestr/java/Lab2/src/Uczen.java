public class Uczen {
    private String imie;
    private String nazwisko;
    private int wiek;
    private double srednia;

    public Uczen() {

    }

    public Uczen(String imie, String nazwisko, int wiek, double srednia) {
        this.imie = imie;
        this.nazwisko = nazwisko;
        this.wiek = wiek;
        this.srednia = srednia;
    }

    @Override
    public String toString() {
        return imie + " " + nazwisko + ", " + wiek + " [" + srednia +  "] ";
    }

}
