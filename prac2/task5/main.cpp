import std;

int main() {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    
    bool result = (x1 == x2) || (y1 == y2);
    std::print("{}\n", result ? "true" : "false");
    return 0;
}