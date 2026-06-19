import std;

class StringBuilder {
private:
	std::string _str;
public:
	StringBuilder() = default;

	void reserve(int n) {
		_str.reserve(n);
	}

	StringBuilder& append(const std::string& str) {
		_str.append(str);
		return *this;
	}

	template<typename T>
	StringBuilder& append(const T n) {
		_str.append(std::to_string(n));
		return *this;
	}

	std::string build() const& {
		std::println("lvalue");
		return _str;
	}

	std::string build()&& {
		std::println("rvalue");
		return std::move(_str);
	}

	int size() const {
		return _str.size();
	}

	int capacity() const {
		return _str.capacity();
	}

	const std::string& str() const {
		return _str;
	}
};

int main() {

	StringBuilder a;
	int n;
	std::println("Какая емкость?");
	std::cin >> n;
	a.reserve(n);
	while(true){
		std::println("выберете данные для ввода 1-string; 2-int; 3-float; 4-выход");
		int choise = 0;
		std::cin >> choise;
		if (choise == 1) {
			std::string str;
			std::cin >> str;
			a.append(str);
		}
		else if (choise == 2) {
			int i = 0;
			std::cin >> i;
			a.append(i);
		}
		else if (choise == 3) {
			float fl = 0;
			std::cin >> fl;
			a.append(fl);
		}
		else if (choise == 4) {
			break;
		}
	}
	std::println("Размер:{}, Емкость: {}",a.size(),a.capacity());
	std::println("Строка: {}",a.str());
	StringBuilder b = a;
	std::string str2 = a.build();
	std::string str3 = std::move(b).build();
	std::println("str2:{}, a:{}",str2,a.str());
	std::println("str3:{}, b:{}",str3,b.str());
}
