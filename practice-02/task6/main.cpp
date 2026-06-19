import std;

int main() {
    std::print("Введите номер года: ");
    int year = 0;
    std::cin >> year;

    bool is_leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    int days = 0;
    if (is_leap) {
        days = 366;
    } else {
        days = 365;
    }

    std::print("Количество дней в году: {}\n", days);
    return 0;
}
