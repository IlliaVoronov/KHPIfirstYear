#ifndef BASECLASS_H
#define BASECLASS_H

#include <functional>

class BaseClass {
public:
    double findMaxSecondDerivative(double start, double end, double step);
    virtual double function(double x) const = 0;

protected:
    double firstDerivative(double x, double delta) const;
    double secondDerivative(double x, double delta) const;
};

#endif // BASECLASS_H
