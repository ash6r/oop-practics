import std;

int main() {
    int n = 0;
    std::cin >> n;
    
    std::print("{}\n", (n % 3600) / 60);
    return 0;
}