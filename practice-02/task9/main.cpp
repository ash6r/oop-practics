import std;

int main() {
    std::print("Введите число a: ");
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::print("Введите число b (b > a): ");
	std::cin >> b;

    int count = b - a + 1;

    std::print("Все целые числа от {} до {}: ", a, b);
    for (int i = a; i <= b; ++i) {
        std::print("{} ", i);
    }
    std::print("\n");

    std::print("Количество чисел: {}\n", count);
    return 0;
}
