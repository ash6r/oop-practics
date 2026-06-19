import std;

int main() {
    std::print("Введите координаты первого поля (x1 y1): ");
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    std::cin >> x1 >> y1;
    std::print("Введите координаты второго поля (x2 y2): ");
    std::cin >> x2 >> y2;

    bool result = (x1 == x2) || (y1 == y2);
    std::print("Ладья может перейти за один ход: {}\n", result ? "true" : "false");
    return 0;
}
