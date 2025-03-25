import java.util.*;
import java.io.*;

abstract class Publication {
    int nofpages;
    String publishername;
    double price;

    Publication() {
        System.out.println("abstract class called ");
    }

    abstract void info(int x, String y, double z);
    abstract void disp();
}

class Book extends Publication {
    void info(int x, String y, double z) {
        this.nofpages = x;
        this.publishername = y;
        this.price = z;
    }

    void disp() {
        System.out.println("The no. of pages is " + this.nofpages);
        System.out.println("The name of publisher is " + this.publishername);
        System.out.println("The price is " + this.price);
    }
}

class Journel extends Publication {
    void info(int x, String y, double z) {
        this.nofpages = x;
        this.publishername = y;
        this.price = z;
    }

    void disp() {
        System.out.println("The no. of pages is " + this.nofpages);
        System.out.println("The name of publisher is " + this.publishername);
        System.out.println("The price is " + this.price);
    }
}

class Library {
    ArrayList<Publication> lib;

    Library() {
        lib = new ArrayList<>();
    }

    void add(Publication pb) {
        lib.add(pb);
    }

    void show() {
        for (Publication pb : lib) {
            pb.disp();
        }
    }

    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        Library lib = new Library();

        for (int i = 0; i < 5; i++) {
            int x = ob.nextInt(); // Read the number of pages
            ob.nextLine(); // Consume the newline character left by nextInt()
            String y = ob.nextLine(); // Read the publisher name
            double z = ob.nextDouble(); // Read the price

            if (i < 3) {
                Publication pb = new Book();
                pb.info(x, y, z);
                lib.add(pb);
            } else {
                Publication pb = new Journel();
                pb.info(x, y, z);
                lib.add(pb);
            }
        }

        lib.show();
    }
}
