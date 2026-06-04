import std;

int main() {
    int n = 0;
	int k = 0;
    std::cin >> n >> k;
    
    int day = ((n - 1) + (k - 1)) % 7 + 1;
    std::print("{}\n", day);
    return 0;
}