import std;

int sum(int num) {
    int n1 = num / 100;
    int n2 = num / 10 % 10;
    int n3 = num % 10;
    int s = n1 + n2 + n3;
    return s;
}

int mul(int num) {
    int n1 = num / 100;
    int n2 = num / 10 % 10;
    int n3 = num % 10;
    int m = n1 * n2 * n3;
    return m;
}

int min_last_h(int sec) {
    int min = sec / 60;
    int total = min % 60;
    return total;
}

int invert_digits(int n) {
    int num = 0;
    int result = 0;
    while (n != 0) {
        num = n % 10;
        result = (result + num) * 10;
        n = n / 10;
    }
    result = result / 10;
    return result;
}

int add_right_digit(int n, int d) {
    if (d < 0 || d > 9) {
        return n;
    }
    return n * 10 + d;
}

bool is_prime(int n) {
    int count = 0;
    for (int i = 2; i < std::sqrt(n) + 1; i++) {
        if (n % i == 0) {
            count++;
            break;
        }
    }
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    if (n > 0) {
        return n * fact(n - 1);
    }
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int digit_sum(int n) {
    if (n < 0) {
        n = -n;
    }
    if (n < 10) {
        return n;
    }
    return (n % 10) + digit_sum(n / 10);
}

int main() {
    int choice = 0;
    std::println("[1] Сумма и произведение цифр трёхзначного числа");
    std::println("[2] Минуты с начала последнего часа (по секундам)");
    std::println("[3] Перевернуть цифры числа");
    std::println("[4] Добавить цифру справа к числу");
    std::println("[5] Проверить, является ли число простым");
    std::println("[6] Вычислить факториал числа");
    std::println("[7] Найти НОД двух чисел по алгоритму Евклида");
    std::println("[8] Сумма цифр числа без циклов");

    std::println("Введите Ваш выбор: ");
    std::cin >> choice;
    switch (choice) {
    case 1: {
        std::print("Введите трехзначное число: ");
        int num = 0;
        std::cin >> num;
        std::println("Сумма цифр трехзначного числа: {}", sum(num));
        std::println("Произведение цифр трехзначного числа: {}", mul(num));
        break;
    }
    case 2: {
        int n = 0;
        std::print("Введите количество секунд: ");
        std::cin >> n;
        std::println("С последнего часа прошло {} минут", min_last_h(n));
        break;
    }
    case 3: {
        int n = 0;
        std::println("Задайте значение параметра n: ");
        std::cin >> n;
        std::println("Итоговый результат {}", invert_digits(n));
        break;
    }
    case 4: {
        int number = 0;
        std::println("Задайте значение параметра n: ");
        std::cin >> number;
        int digit = 0;
        std::println("Задайте значение d: ");
        std::cin >> digit;
        int res = add_right_digit(number, digit);
        std::println("Итоговый результат: {}", res);
        break;
    }
    case 5: {
        int number = 0;
        std::println("Задайте начальное значение n: ");
        std::cin >> number;
        if (is_prime(number)) {
            std::println("Простое число");
        }
        else {
            std::println("Составное число");
        }
        break;
    }
    case 6: {
        int number = 0;
        std::println("Задайте начальное значение: ");
        std::cin >> number;
        std::println("Факториал {} равен {}", number, fact(number));
        break;
    }
    case 7: {
        int a = 0;
        std::print("Введите число a для нахождения НОД: ");
        std::cin >> a;
        int b = 0;
        std::print("Введите число b для нахождения НОД: ");
        std::cin >> b;
        std::println("НОД({}, {}) = {}", a, b, gcd(a, b));
        break;
    }
    case 8: {
        int num = 0;
        std::print("Введите целое число для вычисления суммы его цифр: ");
        std::cin >> num;
        std::println("Сумма цифр числа {} = {}", num, digit_sum(num));
        break;
    }
    default: {
        break;
    }
    }
    return 0;
}