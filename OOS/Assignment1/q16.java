import java.util.*;

interface Fruit {
    void hasAPeel();
}

interface Vegetable {
    void hasARoot();
}

class Tomato implements Fruit, Vegetable {
    public void hasAPeel() {
        System.out.println("Tomato has a peel.");
    }

    public void hasARoot() {
        System.out.println("Tomato has a root.");
    }

    public void printDetails() {
        hasAPeel();
        hasARoot();
    }

    public static void main(String[] args) {
        Tomato tomato = new Tomato();
        tomato.printDetails();
    }
}

