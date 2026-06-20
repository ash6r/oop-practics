#include <fmt/core.h>
#include "fmt_printer.h"

void print_password(const char* password) {
	fmt::print("Сгенерированный пароль: {}\n", password);
}