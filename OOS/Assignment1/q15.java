import java.util.*;

class Tollbooth {
    int carsPassed = 0;
    int carsWithoutPaying = 0;
    int totalCashCollected = 0;

    void carPasses(boolean paid) {
        carsPassed++;
        if (!paid) {
            carsWithoutPaying++;
        } else {
            totalCashCollected += 50;
        }
    }

    void display() {
        System.out.println("The total number of cars passed by without paying: " + carsWithoutPaying);
        System.out.println("Total number of cars passed by: " + carsPassed);
        System.out.println("Total cash collected: Rs. " + totalCashCollected);
    }

    public static void main(String[] args) {
	    Tollbooth tollbooth = new Tollbooth();
	    while(true){
		    Scanner sc = new Scanner(System.in);
		    System.out.println("Enter 1 for paid 2 for not paid 0 to exit");
		    int ch;
		    ch = sc.nextInt();
		    if(ch == 0)
			    break;
			boolean ans = ch == 1 ? true : false;	
		    tollbooth.carPasses(ans);

	    }
	    tollbooth.display();
    }
}

