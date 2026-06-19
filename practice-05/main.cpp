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
		}
		if (_denominator < 0) {
			_numerator = -_numerator;
			_denominator = -_denominator;
		}
		int gcd = std::gcd(_numerator, _denominator);
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

	Fraction& operator++() {
		_numerator += _denominator;
		return *this;
	}

	Fraction operator++(int) {
		Fraction fr(*this);
		_numerator += _denominator;
		return fr;
	}

	Fraction& operator+=(const Fraction& f2) {
		int num = get_numerator() * f2.get_denominator() + f2.get_numerator() * get_denominator();
		int denom = get_denominator() * f2.get_denominator();
		_denominator = denom;
		_numerator = num;
		normalize();
		return *this;
	}

	Fraction& operator-=(const Fraction& f2) {
		int num = get_numerator() * f2.get_denominator() - f2.get_numerator() * get_denominator();
		int denom = get_denominator() * f2.get_denominator();
		_denominator = denom;
		_numerator = num;
		normalize();
		return *this;
	}

	Fraction& operator*=(const Fraction& f2) {
		int num = get_numerator() * f2.get_numerator();
		int denom = get_denominator() * f2.get_denominator();
		_denominator = denom;
		_numerator = num;
		normalize();
		return *this;
	}
};


Fraction operator+(const Fraction& f1, const Fraction& f2) {
	Fraction f3(f1);
	f3 += f2;
	return f3;
}


Fraction operator-(const Fraction& f1, const Fraction& f2) {
	Fraction f3(f1);
	f3 -= f2;
	return f3;
}


Fraction operator*(const Fraction& f1, const Fraction& f2) {
	Fraction f3(f1);
	f3 *= f2;
	return f3;
}


std::ostream& operator<< (std::ostream& out, const Fraction& f1) {
	out << f1.get_numerator() << "/" << f1.get_denominator();
	return out;
}


std::string to_string(const Fraction& f) {
	std::stringstream sstr;
	sstr << f;
	return sstr.str();
}


void print_file(std::string path, const Fraction& f) {
	std::fstream s{ path, std::ios::out | std::ios::trunc };
	if (s.is_open()) {
		s << f;
		s.close();
	}
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
	std::println("Первая дробь: {}", to_string(f1));
	std::println("Вторая дробь: {}", to_string(f2));

	std::print("Введите операцию (+=, -=, *=, +, -, *, ++): ");
	std::string op;
	std::cin >> op;
	if (op == "+=") {
		auto str = to_string(f1);
		std::println("{} += {} = {}", str, to_string(f2), to_string(f1 += f2));
	}
	else if (op == "-=") {
		auto str = to_string(f1);
		std::println("{} -= {} = {}", str, to_string(f2), to_string(f1 -= f2));
	}
	else if (op == "*=") {
		auto str = to_string(f1);
		std::println("{} *= {} = {}", str, to_string(f2), to_string(f1 *= f2));
	}
	else if (op == "+") {
		std::println("{} + {} = {}", to_string(f1), to_string(f2), to_string(f1 + f2));
	}
	else if (op == "-") {
		std::println("{} - {} = {}", to_string(f1), to_string(f2), to_string(f1 - f2));
	}
	else if (op == "*") {
		std::println("{} * {} = {}", to_string(f1), to_string(f2), to_string(f1 * f2));
	}
	else if (op == "++") {
		auto str = to_string(f1);
		auto str2 = to_string(f2);
		std::println("{}++={}, ++{}={}", str, to_string(f1++), str2, to_string(++f2));

	}
	print_file("res.txt", f1);
	return 0;
}
