public class Shape {
    protected int area;
    protected int perimeter;
    private Color color;

    protected void draw();
    protected void delete();
    protected void move();
    protected String getParameters();

    public Shape(int area, int perimeter, Color color) {

    }

    public Shape() {
    }
}
