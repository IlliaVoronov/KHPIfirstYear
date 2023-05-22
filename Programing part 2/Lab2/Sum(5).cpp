#include <iostream>

class MyClass {
public:
    // Constructor with one argument
    MyClass(int value) : value(value) {
        sum += value;
    }

    // Getter for the private data member
    int getValue() const {
        return value;
    }

    // Static function to return the sum of all data members
    static int getSum() {
        return sum;
    }

private:
    int value;
    static int sum;
};

// Initialize the static data member
int MyClass::sum = 0;

int main() {
    // Create several objects
    MyClass obj1(1);
    MyClass obj2(2);
    MyClass obj3(3);

    // Output the calculated sum
    std::cout << "Sum: " << MyClass::getSum() << '\n';

    return 0;
}