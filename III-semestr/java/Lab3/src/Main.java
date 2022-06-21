import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println(
                CaesarCipher.decrypt(
                    CaesarCipher.encrypt("Ala ma kota", 1), 1
                )
        );
    }

    public static int count(char c, String s) {
        return (int) s.chars()
                .filter(character -> character == c)
                .count();

        /*int counter = 0;
        for (char ch : s.toCharArray())
            if (ch == c)
                ++counter;
        return counter;*/
    }

    public static char readCharacter() {
        Scanner scanner = new Scanner(System.in);
        int value = scanner.nextInt();

        if (value < 33 || value > 126)
            return '\0';
        else
            return (char)value;
    }

    public String readLine() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    public boolean isPalindrome(String s) {
        String reversed = new StringBuilder(s).reverse().toString();

        return s.equals(reversed);
    }
}
