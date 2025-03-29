




import java.util.Scanner;

class Book {
    String title;
    String author;
    String publisher;
    double cost;
    int stock;

    Book(String title, String author, String publisher, double cost, int stock) {
        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.cost = cost;
        this.stock = stock;
    }

    boolean isAvailable() {
        return stock > 0;
    }

    void displayBookDetails() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Publisher: " + publisher);
        System.out.println("Cost: Rs. " + cost);
        System.out.println("Stock: " + stock + " copies");
    }

    boolean isStockSufficient(int requiredCopies) {
        return stock >= requiredCopies;
    }

    void updateStock(int soldCopies) {
        stock -= soldCopies;
    }
}

class BookShop {
    private Book[] books;

    BookShop(Book[] books) {
        this.books = books;
    }

    void searchBook(String title, String author, int requiredCopies) {
        boolean found = false;
        for (Book book : books) {
            if (book.title.equalsIgnoreCase(title) && book.author.equalsIgnoreCase(author)) {
                found = true;
                book.displayBookDetails();

                if (book.isStockSufficient(requiredCopies)) {
                    double totalCost = book.cost * requiredCopies;
                    System.out.println("Total cost: Rs. " + totalCost);
                    book.updateStock(requiredCopies);
                } else {
                    System.out.println("Requires copies not in stock.");
                }
                break;
            }
        }

        if (!found) {
            System.out.println("Book not available.");
        }
    }
}
 class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Book[] books = {
            new Book("The Alchemist", "Paulo Coelho", "HarperCollins", 299.50, 10),
            new Book("Java Programming", "Herbert Schildt", "McGraw Hill", 499.99, 5),
            new Book("Effective Java", "Joshua Bloch", "Addison-Wesley", 699.00, 2)
        };

        BookShop bookShop = new BookShop(books);

        System.out.println("Enter book title:");
        String title = scanner.nextLine();

        System.out.println("Enter book author:");
        String author = scanner.nextLine();

        System.out.println("Enter number of copies required:");
        int requiredCopies = scanner.nextInt();

        bookShop.searchBook(title, author, requiredCopies);
    }
}

