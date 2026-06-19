import std;

int main() {
    std::print("Введите номер дня года n (1-365): ");
    int n = 0;
	int k = 0;
    std::cin >> n;
    std::print("Введите день недели k, которым было 1 января (1-7): ");
    std::cin >> k;

    int day = ((n - 1) + (k - 1)) % 7 + 1;
    std::print("Номер дня недели для {}-го дня года: {}\n", n, day);
    return 0;
}
