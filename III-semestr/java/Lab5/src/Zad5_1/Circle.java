public class Circle extends Elipsis {
    private float radius;

    public Circle(int area,
                  int perimeter,
                  Color color,
                  float b,
                  float a,
                  float f1x,
                  float f1y,
                  float f2x,
                  float f2y,
                  float c,
                  float radius
    ) {
        super(area, perimeter, color, b, a, f1x, f1y, f2x, f2y, c);
        this.radius = radius;
    }

    public Circle(float b, float a, float f1x, float f1y, float f2x, float f2y, float c, float radius) {
        super(b, a, f1x, f1y, f2x, f2y, c);
        this.radius = radius;
    }

    @Override
    protected void draw() { super.draw(); }
    @Override
    protected void delete() { super.delete(); }
    @Override
    protected void move() { super.move(); }
    @Override
    protected String getParameters() {
        return super.getParameters() + ", promień: " +  radius;
    }
}
