import java.util.Scanner;

class Automobile {
    String make;
    String type;
    int maxSpeed;
    double price;
    double mileage;
    String registrationNumber;

    public Automobile(String make, String type, int maxSpeed, double price, double mileage, String registrationNumber) {
        this.make = make;
        this.type = type;
        this.maxSpeed = maxSpeed;
        this.price = price;
        this.mileage = mileage;
        this.registrationNumber = registrationNumber;
    }

    public void displayDetails() {
        System.out.println("Make: " + make);
        System.out.println("Type: " + type);
        System.out.println("Max Speed: " + maxSpeed + " km/h");
        System.out.println("Price: " + price + " USD");
        System.out.println("Mileage: " + mileage + " km/l");
        System.out.println("Registration Number: " + registrationNumber);
    }

    public void setMake(String make) {
        this.make = make;
    }

    public String getMake() {
        return make;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public void setMaxSpeed(int maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public int getMaxSpeed() {
        return maxSpeed;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return price;
    }

    public void setMileage(double mileage) {
        this.mileage = mileage;
    }

    public double getMileage() {
        return mileage;
    }

    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    public String getRegistrationNumber() {
        return registrationNumber;
    }
}

class Truck extends Automobile {
    int capacity;
    String hoodType;
    int noOfWheels;

    public Truck(String make, String type, int maxSpeed, double price, double mileage, String registrationNumber, int capacity, String hoodType, int noOfWheels) {
        super(make, type, maxSpeed, price, mileage, registrationNumber);
        this.capacity = capacity;
        this.hoodType = hoodType;
        this.noOfWheels = noOfWheels;
    }

    public void displayDetails() {
        super.displayDetails();
        System.out.println("Capacity: " + capacity + " tons");
        System.out.println("Hood Type: " + hoodType);
        System.out.println("Number of Wheels: " + noOfWheels);
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setHoodType(String hoodType) {
        this.hoodType = hoodType;
    }

    public String getHoodType() {
        return hoodType;
    }

    public void setNoOfWheels(int noOfWheels) {
        this.noOfWheels = noOfWheels;
    }

    public int getNoOfWheels() {
        return noOfWheels;
    }
}

class Car extends Automobile {
    int noOfDoors;
    int seatingCapacity;

    public Car(String make, String type, int maxSpeed, double price, double mileage, String registrationNumber, int noOfDoors, int seatingCapacity) {
        super(make, type, maxSpeed, price, mileage, registrationNumber);
        this.noOfDoors = noOfDoors;
        this.seatingCapacity = seatingCapacity;
    }

    public void displayDetails() {
        super.displayDetails();
        System.out.println("Number of Doors: " + noOfDoors);
        System.out.println("Seating Capacity: " + seatingCapacity + " people");
    }

    public void setNoOfDoors(int noOfDoors) {
        this.noOfDoors = noOfDoors;
    }

    public int getNoOfDoors() {
        return noOfDoors;
    }

    public void setSeatingCapacity(int seatingCapacity) {
        this.seatingCapacity = seatingCapacity;
    }

    public int getSeatingCapacity() {
        return seatingCapacity;
    }
}

 class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter details for Truck:");
        System.out.print("Enter make: ");
        String makeTruck = scanner.nextLine();
        System.out.print("Enter type: ");
        String typeTruck = scanner.nextLine();
        System.out.print("Enter max speed: ");
        int maxSpeedTruck = scanner.nextInt();
        System.out.print("Enter price: ");
        double priceTruck = scanner.nextDouble();
        System.out.print("Enter mileage: ");
        double mileageTruck = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Enter registration number: ");
        String registrationNumberTruck = scanner.nextLine();
        System.out.print("Enter capacity (tons): ");
        int capacityTruck = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter hood type: ");
        String hoodTypeTruck = scanner.nextLine();
        System.out.print("Enter number of wheels: ");
        int noOfWheelsTruck = scanner.nextInt();
        scanner.nextLine();

        Truck truck = new Truck(makeTruck, typeTruck, maxSpeedTruck, priceTruck, mileageTruck, registrationNumberTruck, capacityTruck, hoodTypeTruck, noOfWheelsTruck);

        System.out.println("\nEnter details for Car:");
        System.out.print("Enter make: ");
        String makeCar = scanner.nextLine();
        System.out.print("Enter type: ");
        String typeCar = scanner.nextLine();
        System.out.print("Enter max speed: ");
        int maxSpeedCar = scanner.nextInt();
        System.out.print("Enter price: ");
        double priceCar = scanner.nextDouble();
        System.out.print("Enter mileage: ");
        double mileageCar = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Enter registration number: ");
        String registrationNumberCar = scanner.nextLine();
        System.out.print("Enter number of doors: ");
        int noOfDoorsCar = scanner.nextInt();
        System.out.print("Enter seating capacity: ");
        int seatingCapacityCar = scanner.nextInt();

        Car car = new Car(makeCar, typeCar, maxSpeedCar, priceCar, mileageCar, registrationNumberCar, noOfDoorsCar, seatingCapacityCar);

        System.out.println("\nTruck Details:");
        truck.displayDetails();
        System.out.println("\nCar Details:");
        car.displayDetails();

        scanner.close();
    }
}

