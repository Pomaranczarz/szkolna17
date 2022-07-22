package Zad5_1;

public class Color {
    private final int r;
    private final int g;
    private final int b;

    public Color() {
        this.r = 0;
        this.g = 0;
        this.b = 0;
    }

    public Color(int r, int g, int b) {
        if (r < 0 || g < 0 || b < 0)
            throw new IllegalArgumentException("RGB values have to be non negative");

        this.r = r;
        this.g = g;
        this.b = b;
    }

    @Override
    public String toString() {
        return "(" + r + ", " + g + ", " + b + ")";
    }
}
