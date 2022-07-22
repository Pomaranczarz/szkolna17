public class Shape {
    protected int area;

    protected int perimeter;
    private Color color;

    public int getArea() {
        return area;
    }

    public void setArea(int area) {
        this.area = area;
    }

    public int getPerimeter() {
        return perimeter;
    }

    public void setPerimeter(int perimeter) {
        this.perimeter = perimeter;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    protected void draw() {

    }

    protected void delete() {
        area = 0;
        perimeter = 0;
        color = new Color(0, 0, 0);
    }

    protected void move() {

    }

    protected String getParameters() {
        return "Pole: " + area + ", obwód: " + perimeter + ", kolor: " + color;
    }

    public Shape(int area, int perimeter, Color color) {
        this.area = area;
        this.perimeter = perimeter;
        this.color = color;
    }

    public Shape() {
    }
}
