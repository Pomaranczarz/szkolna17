public class Triangle extends Polygon {
    public Triangle(int area, int perimeter, Color color) {
        super(area, perimeter, color, 3, 3, 180);
    }

    public Triangle() {
        super(3, 3, 180);
    }

    @Override
    protected void draw() {
        super.draw();
    }

    @Override
    protected void delete() {
        super.delete();
    }

    @Override
    protected void move() {
        super.move();
    }

    @Override
    protected String getParameters() {
        return super.getParameters();
    }
}
