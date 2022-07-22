package Zad5_1;

public class Polygon extends Shape {
    private int vertexCount;
    private int sideCount;
    private float innerAnglesSum;

    public int getVertexCount() {
        return vertexCount;
    }
    public void setVertexCount(int vertexCount) {
        this.vertexCount = vertexCount;
    }

    public int getSideCount() {
        return sideCount;
    }
    public void setSideCount(int sideCount) {
        this.sideCount = sideCount;
    }

    public float getInnerAnglesSum() {
        return innerAnglesSum;
    }
    public void setInnerAnglesSum(float innerAnglesSum) {
        this.innerAnglesSum = innerAnglesSum;
    }

    public Polygon(int area, int perimeter, Color color, int vertexCount, int sideCount, float innerAnglesSum) {
        super(area, perimeter, color);
        this.vertexCount = vertexCount;
        this.sideCount = sideCount;
        this.innerAnglesSum = innerAnglesSum;
    }

    public Polygon(int vertexCount, int sideCount, float innerAnglesSum) {
        this.vertexCount = vertexCount;
        this.sideCount = sideCount;
        this.innerAnglesSum = innerAnglesSum;
    }

    double calculateSumOfInnerAngles() {
        return (sideCount - 2) * 180;
    }
}
