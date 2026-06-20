import std;
#include "fmt_printer.h"

std::string generate_password(int length, bool use_digits, bool use_symbols) {
	std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (use_digits) {
		chars += "0123456789";
	}
	if (use_symbols) {
		chars += "!@#$%^&*";
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, static_cast<int>(chars.size()) - 1);

	std::string password;
	for (int i = 0; i < length; ++i) {
		password += chars[dist(gen)];
	}
	return password;
}

int main() {
	int length = 0;
	std::println("Введите длину пароля: ");
	std::cin >> length;

	bool use_digits = false;
	std::println("Включить цифры? (1 - да, 0 - нет): ");
	std::cin >> use_digits;

	bool use_symbols = false;
	std::println("Включить спецсимволы? (1 - да, 0 - нет): ");
	std::cin >> use_symbols;

	std::string password = generate_password(length, use_digits, use_symbols);

	print_password(password.c_str());

	return 0;
}