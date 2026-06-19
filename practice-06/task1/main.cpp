import std;


class String {
private:
	char* _str = nullptr;
	int _size = 0;
	void copy_str(const char* str) {
		if (str != nullptr) {
			_size = std::strlen(str);
			_str = new char[_size + 1];
			std::strcpy(_str, str);
		}


	}
public:
	String() {

	}
	String(const char* str) {
		copy_str(str);
	}
	~String() {
		delete[] _str;
		_str = nullptr;
		_size = 0;
	}
	String(const String& str) {
		copy_str(str._str);
	}
	String(String&& str) {
		_str = str._str;
		_size = str._size;
		str._str = nullptr;
		str._size = 0;
	}
	String& operator = (const String& str) {
	if (this == &str) {
		return *this;
	}
	if (_str != nullptr) {
		delete[] _str;
		_str = nullptr;
		_size = 0;
	}
	copy_str(str._str);
	return *this;
	}
	String& operator = (String&& str) {
		if (this == &str) {
			return *this;
		}
		if (_str != nullptr) {
			delete[] _str;
		}
		_str = str._str;
		_size = str._size;
		str._str = nullptr;
		str._size = 0;
		return *this;
	}
	int size() const {
		return _size;
	}
	char operator[](const int index) const {
		return _str[index];
	}
	const char* get_str() const {
		return _str;
	}
};


std::ostream& operator<<(std::ostream& out, const String& str) {
	if (str.get_str() != nullptr) {
		out << str.get_str();
	}
	return out;
}

namespace std {
	template<>
	struct formatter<String, char> {
		constexpr auto parse(format_parse_context& ctx) {
			auto it = ctx.begin();
			while (it != ctx.end() && *it != '}') {
				++it;
			}
			return it;
		}
		auto format(String p, format_context& ctx) const {
			std::ostringstream oss;
			oss << p;
			const auto s = oss.str();
			return std::copy(s.begin(), s.end(), ctx.out());
		}
	};
}



class StringBuilder {
private:
	std::vector<String> _strs;

public:

	StringBuilder() {}
	void append(String& str) {
		_strs.push_back(str);
	}
};


int main() {
	char str1[] = "Hello world!";

	String str2(str1);
	std::println("{}", str2);
	String str3(str2);
	std::println("{}", str3);
	String str4(std::move(str3));
	std::println("{}", str3);
	std::println("{}", str4);
	String str5 = str4;
	std::println("{}", str5);
	String str6 = std::move(str4);
	std::println("{}", str4);
	std::println("{}", str6);

	std::println("{}", str6[1]);






}
