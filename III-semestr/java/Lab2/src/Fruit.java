public class Fruit {
    private final String name;
    private final Color color;
    private double weight;
    private final String originCountry;

    public Fruit(String name, Color color, double weight, String originCountry) {
        if (weight < 0)
            throw new IllegalArgumentException("Weight has to be positive");

        this.name = name;
        this.color = color;
        this.weight = weight;
        this.originCountry = originCountry;
    }

    @Override
    public String toString() {
        return name + " [" + color + ", " + weight + ", " + originCountry + "] ";
    }

    public void setWeight(double masa) {
        if (masa < 0)
            throw new IllegalArgumentException("Weight has to be positive");

        this.weight = masa;
    }

    public double getWeight() {
        return this.weight;
    }

    public Color getColor() {
        return this.color;
    }

    public String getName() {
        return this.name;
    }

    public String getOriginCountry() {
        return this.originCountry;
    }
}
