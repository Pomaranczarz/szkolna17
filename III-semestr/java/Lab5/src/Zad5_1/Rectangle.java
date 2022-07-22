public class Rectangle extends Polygon {
    public Rectangle(int area, int perimeter, Color color) {
        super(area, perimeter, color, 4, 4, 360);
    }

    public Rectangle() {
        super(4, 4, 360);
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
