#include "BaseClass.h"

double BaseClass::findMaxSecondDerivative(double start, double end, double step) {
    double maxSecondDerivative = secondDerivative(start, step);
    for (double x = start; x <= end; x += step) {
        double currentSecondDerivative = secondDerivative(x, step);
        if (currentSecondDerivative > maxSecondDerivative) {
            maxSecondDerivative = currentSecondDerivative;
        }
    }
    return maxSecondDerivative;
}

double BaseClass::firstDerivative(double x, double delta) const {
    return (function(x + delta) - function(x)) / delta;
}

double BaseClass::secondDerivative(double x, double delta) const {
    return (firstDerivative(x + delta, delta) - firstDerivative(x, delta)) / delta;
}
