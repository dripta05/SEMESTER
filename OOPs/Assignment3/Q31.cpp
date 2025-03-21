#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;
    float height;

public:
    Person(const std::string& name, int age, float height)
        : name(name), age(age), height(height) {}

    void setName(const std::string& name) { this->name = name; }
    std::string getName() const { return name; }
    void setAge(int age) { this->age = age; }
    int getAge() const { return age; }
    void setHeight(float height) { this->height = height; }
    float getHeight() const { return height; }

    virtual void printDetails() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\nHeight: " << height << std::endl;
    }
};

class Student : public Person {
private:
    int roll;
    int yearOfAdmission;

public:
    Student(const std::string& name, int age, float height, int roll, int yearOfAdmission)
        : Person(name, age, height), roll(roll), yearOfAdmission(yearOfAdmission) {}

    void setRoll(int roll) { this->roll = roll; }
    int getRoll() const { return roll; }
    void setYearOfAdmission(int yearOfAdmission) { this->yearOfAdmission = yearOfAdmission; }
    int getYearOfAdmission() const { return yearOfAdmission; }

    void printDetails() const override {
        Person::printDetails();
        std::cout << "Roll: " << roll << "\nYear of Admission: " << yearOfAdmission << std::endl;
    }
};

int main() {
    Person person1("Alice", 30, 5.5);
    Student student1("Bob", 20, 6.0, 101, 2022);
    Student student2("Charlie", 21, 5.8, 102, 2021);

    Person* people[4];
    people[0] = &person1;
    people[1] = &student1;
    people[2] = &student2;
    people[3] = new Person("Dave", 40, 5.9);

    for (int i = 0; i < 4; ++i) {
        people[i]->printDetails();
        std::cout << std::endl;
    }

    delete people[3];

    return 0;
}

