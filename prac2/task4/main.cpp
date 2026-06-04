import std;

int main() {
    int num = 0;
    std::cin >> num;
    
    int d1 = num / 100;
    int d2 = (num / 10) % 10;
    int d3 = num % 10;
    
    bool result = (d1 < d2) && (d2 < d3);
    std::print("{}\n", result ? "true" : "false");
    return 0;
}