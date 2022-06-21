public class SomeClass {
    private int intValue;
    private char charValue;
    private String strValue;

    @Override
    public String toString() {
        return intValue + " " + charValue + " " + strValue;
    }

    static void printNumbersFromZeroTo(int value) {
        for (int i = 0; i <= value; ++i)
            System.out.println(i);
    }
}