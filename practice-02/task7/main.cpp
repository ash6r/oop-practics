import std;

int main() {
    std::print("Введите целое число от 1 до 999: ");
    int num = 0;
    std::cin >> num;

    if (num % 2 == 0) {
        std::print("четное ");
    } else {
        std::print("нечетное ");
    }

    if (num < 10) {
        std::print("однозначное число\n");
    } else if (num < 100) {
        std::print("двузначное число\n");
    } else {
        std::print("трехзначное число\n");
    }

    return 0;
}
