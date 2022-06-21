import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println(getLengthOfLongestSequenceOfZeroesSurroundedByOnes("0110000000001000001"));
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

    public static String decToBin(int number) {
        StringBuilder stringBuilder = new StringBuilder();
        while (number > 0) {
            stringBuilder.append(number % 2);
            number /= 2;
        }

        return stringBuilder.reverse().toString();
    }

    public static int getLengthOfLongestSequenceOfZeroesSurroundedByOnes(String binaryNumber) {
        int zeroesCount = 0;
        int maxZeroesLen = 0;

        binaryNumber = binaryNumber.substring(binaryNumber.indexOf('1')); // remove leading zeroes

        for (int i = 0; i < binaryNumber.length(); i++) {
            if (binaryNumber.charAt(i) == '1') {
                if (zeroesCount > maxZeroesLen)
                    maxZeroesLen = zeroesCount;

                zeroesCount = 0;

            } else if (binaryNumber.charAt(i) == '0') {
                zeroesCount++;
            }
        }

        return maxZeroesLen;
    }
}
