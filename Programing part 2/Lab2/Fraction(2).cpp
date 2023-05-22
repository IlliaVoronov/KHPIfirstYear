#include <iostream>

using namespace std;

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
        reduce();
    }

    void reduce() {
        int gcd = calculateGCD(m_numerator, m_denominator);
        m_numerator /= gcd;
        m_denominator /= gcd;
    }

    Fraction operator+(const Fraction& other) const {
        int numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
        int denominator = m_denominator * other.m_denominator;
        return Fraction(numerator, denominator);
    }

    Fraction operator-(const Fraction& other) const {
        int numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
        int denominator = m_denominator * other.m_denominator;
        return Fraction(numerator, denominator);
    }

    Fraction operator*(const Fraction& other) const {
        int numerator = m_numerator * other.m_numerator;
        int denominator = m_denominator * other.m_denominator;
        return Fraction(numerator, denominator);
    }

    Fraction operator/(const Fraction& other) const {
        int numerator = m_numerator * other.m_denominator;
        int denominator = m_denominator * other.m_numerator;
        return Fraction(numerator, denominator);
    }

    bool operator<(const Fraction& other) const {
        return m_numerator * other.m_denominator < other.m_numerator * m_denominator;
    }

    bool operator<=(const Fraction& other) const {
        return m_numerator * other.m_denominator <= other.m_numerator * m_denominator;
    }

    bool operator>(const Fraction& other) const {
        return m_numerator * other.m_denominator > other.m_numerator * m_denominator;
    }

    bool operator>=(const Fraction& other) const {
        return m_numerator * other.m_denominator >= other.m_numerator * m_denominator;
    }

    friend istream& operator>>(istream& in, Fraction& fraction) {
        char separator;
        in >> fraction.m_numerator >> separator >> fraction.m_denominator;
        fraction.reduce();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Fraction& fraction) {
        if (fraction.m_denominator == 1 || fraction.m_numerator == 0) {
            out << fraction.m_numerator;
        } else if (abs(fraction.m_numerator) >= fraction.m_denominator) {
            int whole_part = fraction.m_numerator / fraction.m_denominator;
            int numerator = fraction.m_numerator % fraction.m_denominator;
            out << whole_part << " " << abs(numerator) << "/" << fraction.m_denominator;
        } else {
            out << fraction.m_numerator << "/" << fraction.m_denominator;
        }
        return out;
    }

private:
    int m_numerator;
    int m_denominator;

    int calculateGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return calculateGCD(b, a % b);
    }
};

int main() {
    Fraction f1(3, 4);
    Fraction f2(2, 5);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    Fraction sum = f1 + f2;
    cout << "f1 + f2 = " << sum << endl;

    Fraction diff = f1 - f2;
    cout << "f1 - f2 = " << diff << endl;

    Fraction prod = f1 * f2;
    cout << "f1 * f2 = " << prod << endl;

    Fraction quo = f1 / f2;
    cout << "f1 / f2 = " << quo << endl;

    cout << "f1 < f2 : " << (f1 < f2) << endl;
    cout << "f1 <= f2 : " << (f1 <= f2) << endl;
    cout << "f1 > f2 : " << (f1 > f2) << endl;
    cout << "f1 >= f2 : " << (f1 >= f2) << endl;

    Fraction f3(7, 2);
    cout << "f3 = " << f3 << endl;

    Fraction f4(-7, 2);
    cout << "f4 = " << f4 << endl;

    Fraction f5(0, 5);
    cout << "f5 = " << f5 << endl;

    return 0;
}
