import java.util.*;

class Account {
    int accountNumber;
    String holderName;
    double balance;

    Account(int accountNumber, String holderName, double balance) {
        this.accountNumber = accountNumber;
        this.holderName = holderName;
        this.balance = balance;
    }

    public int getAccountNumber() {
        return accountNumber;
    }

    public String getHolderName() {
        return holderName;
    }

    public double getBalance() {
        return balance;
    }

    public void setAccountNumber(int accountNumber) {
        this.accountNumber = accountNumber;
    }

    public void setHolderName(String holderName) {
        this.holderName = holderName;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public void displayAccountDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Holder: " + holderName);
        System.out.println("Balance: " + balance);
    }
}

class SavingsAccount extends Account {
    double interestRate;

    SavingsAccount(int accountNumber, String holderName, double balance, double interestRate) {
        super(accountNumber, holderName, balance);
        this.interestRate = interestRate;
    }

    public double calculateYearlyInterest() {
        return balance * (interestRate / 100);
    }

    public void displayAccountDetails() {
        super.displayAccountDetails();
        System.out.println("Interest Rate: " + interestRate + "%");
        System.out.println("Yearly Interest: " + calculateYearlyInterest());
    }
}

class CurrentAccount extends Account {
    CurrentAccount(int accountNumber, String holderName, double balance) {
        super(accountNumber, holderName, balance);
    }

    public void displayAccountDetails() {
        super.displayAccountDetails();
    }
}

class Manager {
    List<Account> accounts;

    Manager() {
        accounts = new ArrayList<>();
    }

    public void addAccount(Account account) {
        accounts.add(account);
    }

    public void displayAllAccounts() {
        for (Account account : accounts) {
            System.out.println("---- Account Details ----");
            account.displayAccountDetails();
            System.out.println();
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Manager manager = new Manager();

        for (int i = 0; i < 2; i++) {
            System.out.print("Enter Savings Account details\n");
            System.out.print("Account Number: ");
            int accountNumber = sc.nextInt();
            sc.nextLine();
            System.out.print("Holder Name: ");
            String holderName = sc.nextLine();
            System.out.print("Balance: ");
            double balance = sc.nextDouble();
            System.out.print("Interest Rate: ");
            double interestRate = sc.nextDouble();

            SavingsAccount savingsAccount = new SavingsAccount(accountNumber, holderName, balance, interestRate);
            manager.addAccount(savingsAccount);
        }

        for (int i = 0; i < 3; i++) {
            System.out.print("Enter Current Account details\n");
            System.out.print("Account Number: ");
            int accountNumber = sc.nextInt();
            sc.nextLine();
            System.out.print("Holder Name: ");
            String holderName = sc.nextLine();
            System.out.print("Balance: ");
            double balance = sc.nextDouble();

            CurrentAccount currentAccount = new CurrentAccount(accountNumber, holderName, balance);
            manager.addAccount(currentAccount);
        }

        manager.displayAllAccounts();
    }
}

