import java.util.Scanner;

class Book {
    String author;
    String title;
    String publisher;
    double cost;
    int stock;

    public Book(String author, String title, String publisher, double cost, int stock) {
        this.author = author;
        this.title = title;
        this.publisher = publisher;
        this.cost = cost;
        this.stock = stock;
    }

    public void displayBookInfo() {
        System.out.println("Author: " + author);
        System.out.println("Title: " + title);
        System.out.println("Publisher: " + publisher);
        System.out.println("Cost: " + cost);
        System.out.println("Stock: " + stock);
    }

    public boolean isAvailable(int requestedCopies) {
        return stock >= requestedCopies;
    }

    public double calculateTotalCost(int requestedCopies) {
        return cost * requestedCopies;
    }
}

class BookshopInventory {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Book[] books = {
            new Book("Author1", "Book1", "Publisher1", 100.0, 10),
            new Book("Author2", "Book2", "Publisher2", 150.0, 5),
            new Book("Author3", "Book3", "Publisher3", 200.0, 1),
	    new Book("Author4", "Book4", "Publisher4", 350.0 ,3)       
 };

        System.out.print("Enter Book Title: ");
        String title = scanner.nextLine();
        System.out.print("Enter Book Author: ");
        String author = scanner.nextLine();

        boolean bookFound = false;
        for (Book book : books) {
            if (book.title.equalsIgnoreCase(title) && book.author.equalsIgnoreCase(author)) {
                bookFound = true;
                book.displayBookInfo();
                System.out.print("Enter the number of copies required: ");
                int requestedCopies = scanner.nextInt();
                if (book.isAvailable(requestedCopies)) {
                    System.out.println("Total cost: " + book.calculateTotalCost(requestedCopies));
                } else {
                    System.out.println("Requires copies not in stock.");
                }
		break;
	    }
	}

	if (!bookFound) {
		System.out.println("Book not found.");
	}

	scanner.close();
    }
}

