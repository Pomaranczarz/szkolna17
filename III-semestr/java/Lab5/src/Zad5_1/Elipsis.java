package Zad5_1;

public class Elipsis extends Shape {
    private float b;
    private float a;
    private float F1x;
    private float F1y;
    private float F2x;
    private float F2y;
    private float c;

    public float getB() { return b;}
    public void setB(float b) { this.b = b; }

    public float getA() { return a; }
    public void setA(float a) { this.a = a;}

    public float getF1x() { return F1x; }
    public void setF1x(float f1x) { F1x = f1x; }

    public float getF1y() { return F1y; }
    public void setF1y(float f1y) { F1y = f1y; }

    public float getF2x() { return F2x; }
    public void setF2x(float f2x) { F2x = f2x; }

    public float getF2y() { return F2y; }
    public void setF2y(float f2y) { F2y = f2y; }

    public float getC() { return c; }
    public void setC(float c) { this.c = c; }

    @Override
    protected void draw() { super.draw(); }
    @Override
    protected void delete() { super.delete(); }
    @Override
    protected void move() { super.move(); }

    public Elipsis(int area, int perimeter, Color color, float b, float a, float f1x, float f1y, float f2x, float f2y, float c) {
        super(area, perimeter, color);
        this.b = b;
        this.a = a;
        F1x = f1x;
        F1y = f1y;
        F2x = f2x;
        F2y = f2y;
        this.c = c;
    }

    public Elipsis(float b, float a, float f1x, float f1y, float f2x, float f2y, float c) {
        this.b = b;
        this.a = a;
        F1x = f1x;
        F1y = f1y;
        F2x = f2x;
        F2y = f2y;
        this.c = c;
    }

    @Override
    protected String getParameters() {
        return super.getParameters() + ", półoś wielka: " + a + ", półoś mała: " + b
                + ", pozycja ogniska F1: (" + F1x + ", " + F1y + "), pozycja ogniska F2: (" + F2x + ", " + F2y
                + "), odległość ognisk od środka: " + c;
    }

    double calculateC() {
        return Math.sqrt(a * a - b * b);
    }

}
