
import java.util.Scanner;

class Date {
	int day;
	int month;
	int year;

	public Date() {
		this.day = 1;
		this.month = 1;
		this.year = 1970;
	}

	public Date(int day) {
		this.day = day;
		this.month = 1;
		this.year = 1970;
	}

	public Date(int day, int month) {
		this.day = day;
		this.month = month;
		this.year = 1970;
	}

	public Date(int day, int month, int year) {
		this.day = day;
		this.month = month;
		this.year = year;
	}

	private boolean isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	private int daysInMonth(int month, int year) {
		switch (month) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				return 31;
			case 4: case 6: case 9: case 11:
				return 30;
			case 2:
				return isLeapYear(year) ? 29 : 28;
			default:
				return 0;
		}
	}

	public void printDate() {
		System.out.println(day + "/" + month + "/" + year);
	}

	public void getPreviousDay() {
		if (day > 1) {
			day--;
		} else {
			if (month > 1) {
				month--;
				day = daysInMonth(month, year);
			} else {
				year--;
				month = 12;
				day = 31;
			}
		}
	}

	public void getNextDay() {
		if (day < daysInMonth(month, year)) {
			day++;
		} else {
			if (month < 12) {
				month++;
				day = 1;
			} else {
				year++;
				month = 1;
				day = 1;
			}
		}
	}
}
class DateDemo {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter day: ");
		int day = scanner.nextInt();
		System.out.print("Enter month: ");
		int month = scanner.nextInt();
		System.out.print("Enter year: ");
		int year = scanner.nextInt();

		Date date = new Date(day, month, year);

		System.out.print("Current Date: ");
		date.printDate();

		date.getPreviousDay();
		System.out.print("Previous Day: ");
		date.printDate();

		date.getNextDay();
		date.getNextDay();
		System.out.print("Next Day: ");
		date.printDate();

		scanner.close();
	}
}

