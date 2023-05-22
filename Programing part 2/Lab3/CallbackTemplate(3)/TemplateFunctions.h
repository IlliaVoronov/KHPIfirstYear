#ifndef TEMPLATEFUNCTIONS_H
#define TEMPLATEFUNCTIONS_H

#include <functional>

template<typename T>
double solveTask1_2(const T& obj, double start, double end, double step);

template<typename T>
double firstDerivative(const T& obj, double x, double delta);

template<typename T>
double secondDerivative(const T& obj, double x, double delta);

template<typename T>
double solveTask1_2(const T& obj, double start, double end, double step) {
    std::function<double(double)> func;
    if constexpr (std::is_class_v<T>) {
        func = obj;
    } else {
        func = obj;
    }

    double maxSecondDerivative = secondDerivative(func, start, step);
    for (double x = start; x <= end; x += step) {
        double currentSecondDerivative = secondDerivative(func, x, step);
        if (currentSecondDerivative > maxSecondDerivative) {
            maxSecondDerivative = currentSecondDerivative;
        }
    }
    return maxSecondDerivative;
}

template<typename T>
double firstDerivative(const T& obj, double x, double delta) {
    return (obj(x + delta) - obj(x)) / delta;
}

template<typename T>
double secondDerivative(const T& obj, double x, double delta) {
    return (firstDerivative(obj, x + delta, delta) - firstDerivative(obj, x, delta)) / delta;
}

#endif // TEMPLATEFUNCTIONS_H
