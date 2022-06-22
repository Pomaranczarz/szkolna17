import java.util.Arrays;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Circle[] circles = createCircleArray(10);

        printCircles(circles);
    }

    public static int[] createArray(int size) {
        int[] result = new int[size];
        for (int i = 0; i < size; ++i)
            result[i] = i;

        return result;
    }

    public static void printOneDimensionalArraySeparated(int[] array) {
        int[] sums = new int[(int)Math.sqrt(array.length)];
        for (int i = 0; i < array.length; ++i) {
            System.out.printf("%02d, ", array[i]);

            if ((i + 1) % 10 == 0)
                System.out.println();

            sums[i % 10] += array[i];
        }

        for (int sum : sums)
            System.out.printf("%02d, ", sum / 10);
    }

    public static int[][] generateRandom2DArray() {
        Random rng = new Random();
        int size = rng.nextInt(31) - 10;

        int[][] result = new int[size][size];
        for (int i = 0; i < result.length; ++i) {
            for (int j = 0; j < result[i].length; ++j) {
                if (i == j)
                    result[i][j] = rng.nextBoolean() ? 1 : -1;
                else
                    result[i][j] = rng.nextInt(41) - 20;
            }
        }

        return result;
    }

    public static float getRatioBetweenSumOfElementsOnEvenRowAndOddColumnIndexes(int[][] array) {
        int evenSum = 0;
        int oddSum = 0;

        for (int i = 0; i < array.length; ++i) {
            for (int j = 0; j < array.length; ++j) {
                if (i % 2 == 0)
                    evenSum += array[i][j];
                else if (j % 2 != 0)
                    oddSum += array[i][j];
            }
        }

        return evenSum * 1.f / oddSum;
    }

    public static Circle[] createCircleArray(int size) {
        Circle[] circles = new Circle[size];
        for (int i = 0; i < circles.length; ++i)
            circles[i] = new Circle();

        return circles;
    }

    enum RelativeCirclesPosition { INTERSECTING, TOUCHING_INTERNALLY, TOUCHING_EXTERNALLY, ONE_INSIDE_ANOTHER, OUTSIDE }

    public static RelativeCirclesPosition getRelativeCirclesPosition(Circle c1, Circle c2) {
        double distanceBetweenMids = Math.sqrt(Math.pow(c2.x - c1.x, 2) + Math.pow(c2.y - c1.y, 2));

        if (distanceBetweenMids > c1.radius + c2.radius)
            return RelativeCirclesPosition.OUTSIDE;
        else if (distanceBetweenMids == c1.radius + c2.radius)
            return RelativeCirclesPosition.TOUCHING_EXTERNALLY;
        else if (distanceBetweenMids == Math.abs(c1.radius - c2.radius))
            return RelativeCirclesPosition.TOUCHING_INTERNALLY;
        else if (distanceBetweenMids > Math.abs(c1.radius + c2.radius) && distanceBetweenMids < c1.radius + c2.radius)
            return RelativeCirclesPosition.INTERSECTING;
        else
            return RelativeCirclesPosition.ONE_INSIDE_ANOTHER;
    }

    public static void printCircles(Circle[] circles) {
        for (Circle circle : circles)
            System.out.println(circle);
    }
}
