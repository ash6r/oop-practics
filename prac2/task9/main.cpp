import std;

int main() {
    int a = 0;
    int b = 0;
    std::cin >> a;
	std::cin >> b;
    
    int count = b - a + 1;
    
    for (int i = a; i <= b; ++i) {
        std::print("{} ", i);
    }
    std::print("\n");
    
    std::print("{}\n", count);
    return 0;
}