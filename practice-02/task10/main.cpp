import std;

int main() {
    std::print("Введите вещественное число a: ");
    double a = 0.0;
    std::cin >> a;

    std::print("Введите целое число n (n > 0): ");
    int n = 0;
    std::cin >> n;

    double power = 1.0;
    std::print("Целые степени числа {} от 1 до {}: ", a, n);
    for (int i = 1; i <= n; ++i) {
        power *= a;
        std::print("{} ", power);
    }
    std::print("\n");

    return 0;
}
