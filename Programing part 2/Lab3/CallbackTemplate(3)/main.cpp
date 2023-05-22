#include <iostream>
#include <cmath>
#include "TemplateFunctions.h"

typedef double (*FuncPtr)(double);

double func1(double x) {
    return std::sin(x);
}

double func2(double x) {
    return x * x * x;
}

int main() {
    double start = 0.0;
    double end = 5.0;
    double step = 0.0001;

    double maxSecondDerivative1 = solveTask1_2(func1, start, end, step);
    std::cout << "Maximum value of the second derivative for func1: " << maxSecondDerivative1 << std::endl;

    FuncPtr funcPtr = &func2;
    double maxSecondDerivative2 = solveTask1_2(funcPtr, start, end, step);
    std::cout << "Maximum value of the second derivative for func2: " << maxSecondDerivative2 << std::endl;

    return 0;
}
