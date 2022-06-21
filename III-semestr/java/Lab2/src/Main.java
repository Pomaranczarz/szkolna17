import java.util.function.Consumer;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
      /*  SomeClass someClass = new SomeClass();

        System.out.println(someClass);

        SomeClass.printNumbersFromZeroTo(54);

        Uczen u1 = new Uczen();
        Uczen u2 = new Uczen("Adam", "Kowalski", 20, 4.20f);
        Uczen u3 = new Uczen("Anna", "Nowak", 19, 3.45f);

        System.out.println("u1 = " + u1);
        System.out.println("u2 = " + u2);
        System.out.println("u3 = " + u3);*/

        /*for (int i = 5; i <= 80; ++i) {
            System.out.print(i + " ");
            if (i % 15 == 0)
                System.out.println();
        }

        {
            System.out.println();
            int i = 5;
            while (i <= 80) {
                System.out.print(i + " ");
                if (i % 15 == 0)
                    System.out.println();

                ++i;
            }

            System.out.println();
            i = 5;
            do {
                System.out.print(i + " ");
                if (i % 15 == 0)
                    System.out.println();
            } while (++i <= 80);
        }

        System.out.println();
        for (int i : IntStream.range(5, 80).toArray()) {
            System.out.print(i + " ");
            if (i % 15 == 0)
                System.out.println();
        }*/

        printFibonacci(10);
    }

    public boolean canConstructTriangle(int a, int b, int c) {
        if (a <= 0 || b <= 0 || c <= 0)
            throw new IllegalArgumentException("Length has to be positive");

        return a + b > c && a + c > b && b + c > a;
    }

    enum TriangleType { EQUIANGULAR, ACUTE, RIGHT, OBTUSE }

    private interface GetTriangleType {
        TriangleType getType(int max, int a, int b);
    }

    public TriangleType getTriangleType(int a, int b, int c) {
        if (!canConstructTriangle(a, b, c))
            throw new IllegalArgumentException("Cannot construct triangle from these values");
        else if (a == b && b == c)
            return TriangleType.EQUIANGULAR;
        else {
            GetTriangleType triangleTypeResolver = (int max, int x, int y) -> {
                int shorterSquaresSum = x * x + y * y;
                int maxLenSquared = max * max;
                if (shorterSquaresSum == maxLenSquared)
                    return TriangleType.RIGHT;
                else if (shorterSquaresSum < maxLenSquared)
                    return TriangleType.ACUTE;
                else
                    return TriangleType.OBTUSE;
            };

            int maxLen = Math.max(Math.max(a, b), c);
            if (maxLen == a)
                return triangleTypeResolver.getType(a, b, c);
            else if (maxLen == b)
                return triangleTypeResolver.getType(b, a, c);
            else
                return triangleTypeResolver.getType(c, a, b);
        }
    }

    public void printDivisibleBy13InRange(int rangeBeginInclusive, int rangeEndInclusive) {
        for (int i = rangeBeginInclusive; i <= rangeBeginInclusive; ++i)
            if (i % 13 == 0)
                System.out.print(i + " ");
    }

    public static void printFibonacci(int n) {
        for (int i = 1; i <= n; ++i)
            System.out.println(fibonacci(i));
    }

    private static int fibonacci(int n) {
        final double sqrt_5 = Math.sqrt(5);

        if (n == 1 || n == 2)
            return 1;
        else
            return (int)((Math.pow(1 + sqrt_5, n) - Math.pow(1 - sqrt_5, n)) / (Math.pow(2, n) * sqrt_5));
    }
}
