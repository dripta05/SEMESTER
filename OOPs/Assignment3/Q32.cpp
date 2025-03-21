#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    float salary;

public:
    Employee(const std::string& name, float salary)
        : name(name), salary(salary) {}

    void setName(const std::string& name) { this->name = name; }
    std::string getName() const { return name; }
    void setSalary(float salary) { this->salary = salary; }
    float getSalary() const { return salary; }

    virtual void printDetails() const {
        std::cout << "Name: " << name << "\nSalary: " << salary << std::endl;
    }

    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    std::string type;
    float allowance;

public:
    Manager(const std::string& name, float salary, const std::string& type, float allowance)
        : Employee(name, salary), type(type), allowance(allowance) {}

    void setType(const std::string& type) { this->type = type; }
    std::string getType() const { return type; }
    void setAllowance(float allowance) { this->allowance = allowance; }
    float getAllowance() const { return allowance; }

    void printDetails() const override {
        Employee::printDetails();
        std::cout << "Type: " << type << "\nAllowance: " << allowance << std::endl;
    }
};

class Clerk : public Employee {
private:
    float allowance;

public:
    Clerk(const std::string& name, float salary, float allowance)
        : Employee(name, salary), allowance(allowance) {}

    void setAllowance(float allowance) { this->allowance = allowance; }
    float getAllowance() const { return allowance; }

    void printDetails() const override {
        Employee::printDetails();
        std::cout << "Allowance: " << allowance << std::endl;
    }
};

int main() {
    Employee emp1("John Doe", 50000);
    Manager mgr1("Jane Smith", 70000, "Senior", 10000);
    Manager mgr2("Alice Brown", 75000, "Junior", 8000);
    Clerk clk1("Bob White", 30000, 2000);
    Clerk clk2("Carol Black", 32000, 2200);

    Employee* employees[6];
    employees[0] = &emp1;
    employees[1] = &mgr1;
    employees[2] = &mgr2;
    employees[3] = &clk1;
    employees[4] = &clk2;
    employees[5] = new Employee("Emily Green", 55000);

    float totalSalary = 0;

    for (int i = 0; i < 6; ++i) {
        employees[i]->printDetails();
        std::cout << std::endl;
        totalSalary += employees[i]->getSalary();
    }

    std::cout << "Total Salary: " << totalSalary << std::endl;

    delete employees[5];

    return 0;
}

