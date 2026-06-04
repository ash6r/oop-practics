import std;

int main() {
    double a = 0.0;
    std::cin >> a;
    
    int n = 0;
    std::cin >> n;
    
    double power = 1.0;
    for (int i = 1; i <= n; ++i) {
        power *= a;
        std::print("{} ", power);
    }
    std::print("\n");
    
    return 0;
}