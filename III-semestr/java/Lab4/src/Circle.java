import java.util.Random;

public class Circle {
    public int x;
    public int y;
    public int radius;

    public Circle() {
        Random rng = new Random();
        x = rng.nextInt(91) + 5;
        y = rng.nextInt(91) + 5;
        radius = rng.nextInt(5) + 1;
    }

    @Override
    public String toString() {
        return "{ x: " + x + ", y: " + y + ", radius: " + radius + " }";
    }
}
