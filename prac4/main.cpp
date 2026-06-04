import std;

class Fraction {
private:
    int _numerator = 0;
    int _denominator = 1;

    void normalize() {
        if (_denominator == 0) {
            _denominator = 1;
        }
        if (_numerator == 0) {
            _denominator = 1;
            return;
        }
        if (_denominator < 0) {
            _numerator = -_numerator;
            _denominator = -_denominator;
        }
        int gcd = std::gcd(std::abs(_numerator), std::abs(_denominator));
        _numerator = _numerator / gcd;
        _denominator = _denominator / gcd;
    }

public:
    Fraction(int numerator) {
        _numerator = numerator;
        normalize();
    }

    Fraction(int numerator, int denominator) {
        _numerator = numerator;
        _denominator = denominator;
        normalize();
    }

    int get_numerator() const {
        return _numerator;
    }

    int get_denominator() const {
        return _denominator;
    }
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int numerator = f1.get_numerator() * f2.get_denominator() + f2.get_numerator() * f1.get_denominator();
    int denominator = f1.get_denominator() * f2.get_denominator();
    Fraction f3(numerator, denominator);
    return f3;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int numerator = f1.get_numerator() * f2.get_numerator();
    int denominator = f1.get_denominator() * f2.get_denominator();
    Fraction f3(numerator, denominator);
    return f3;
}

std::string to_string(const Fraction& f) {
    return std::format("{}/{}", f.get_numerator(), f.get_denominator());
}

int main() {
    int num1 = 0;
    std::println("Введите числитель 1: ");
    std::cin >> num1;
    int denom1 = 1;
    std::println("Введите знаменатель 1: ");
    std::cin >> denom1;
    Fraction f1(num1, denom1);

    int num2 = 0;
    std::println("Введите числитель 2: ");
    std::cin >> num2;
    int denom2 = 1;
    std::println("Введите знаменатель 2: ");
    std::cin >> denom2;
    Fraction f2(num2, denom2);

    Fraction f3 = f1 + f2;
    std::println("{} + {} = {}", to_string(f1), to_string(f2), to_string(f3));
    Fraction f4 = f1 * f2;
    std::println("{} * {} = {}", to_string(f1), to_string(f2), to_string(f4));
    return 0;
}