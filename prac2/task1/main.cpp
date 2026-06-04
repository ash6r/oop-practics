import std;

int main() {
    int num = 0;
    std::cin >> num;
    
    int d1 = num / 100;
    int d2 = (num / 10) % 10;
    int d3 = num % 10;
    
    std::print("{} {}\n", d1 + d2 + d3, d1 * d2 * d3);
	return 0;
}