import java.util.*;

interface Shape {
    void draw();
    void move(int dx, int dy);
    double area();
    void rotate(double angle);
}

class Circle implements Shape {
    private double radius;
    private int x, y;

    public Circle(double radius, int x, int y) {
        this.radius = radius;
        this.x = x;
        this.y = y;
    }

    public void draw() {
        System.out.println("Drawing Circle at (" + x + ", " + y + ") with radius " + radius);
    }

    public void move(int dx, int dy) {
        x += dx;
        y += dy;
        System.out.println("Circle moved to (" + x + ", " + y + ")");
    }

    public double area() {
        return Math.PI * radius * radius;
    }

    public void rotate(double angle) {
        System.out.println("Rotating Circle by " + angle + " degrees.");
    }

    public void printDetails() {
        System.out.println("Circle - Radius: " + radius + ", Position: (" + x + ", " + y + "), Area: " + area());
    }
}

class Rectangle implements Shape {
    private double length, width;
    private int x, y;

    public Rectangle(double length, double width, int x, int y) {
        this.length = length;
        this.width = width;
        this.x = x;
        this.y = y;
    }

    public void draw() {
        System.out.println("Drawing Rectangle at (" + x + ", " + y + ") with length " + length + " and width " + width);
    }

    public void move(int dx, int dy) {
        x += dx;
        y += dy;
        System.out.println("Rectangle moved to (" + x + ", " + y + ")");
    }

    public double area() {
        return length * width;
    }

    public void rotate(double angle) {
        System.out.println("Rotating Rectangle by " + angle + " degrees.");
    }

    public void printDetails() {
        System.out.println("Rectangle - Length: " + length + ", Width: " + width + ", Position: (" + x + ", " + y + "), Area: " + area());
    }
}
 class Main {
    public static void main(String[] args) {
        Circle circle1 = new Circle(5.0, 0, 0);
        Circle circle2 = new Circle(3.0, 10, 10);
        
        Rectangle rectangle1 = new Rectangle(4.0, 6.0, 1, 1);
        Rectangle rectangle2 = new Rectangle(7.0, 3.0, 5, 5);
        Rectangle rectangle3 = new Rectangle(2.0, 8.0, 10, 10);

        System.out.println("Before moving:");
        circle1.printDetails();
        circle2.printDetails();
        rectangle1.printDetails();
        rectangle2.printDetails();
        rectangle3.printDetails();

        System.out.println("\nMoving shapes...");
        circle1.move(5, 5);
        circle2.move(-3, -3);
        rectangle1.move(2, 3);
        rectangle2.move(-4, 4);
        rectangle3.move(1, -1);

        System.out.println("\nAfter moving:");
        circle1.printDetails();
        circle2.printDetails();
        rectangle1.printDetails();
        rectangle2.printDetails();
        rectangle3.printDetails();
    }
}

