#include <iostream>
#include "DerivedClass.h"

int main() {
    DerivedClass derived;
    double start = 0.0;
    double end = 10.0;
    double step = 0.0001;

    double maxSecondDerivative = derived.findMaxSecondDerivative(start, end, step);
    std::cout << "Maximum value of the second derivative: " << maxSecondDerivative << std::endl;

    return 0;
}
