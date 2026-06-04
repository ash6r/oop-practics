import std;

int main() {
    int num = 0;
    std::cin >> num;
    
    int hundreds = num / 100;
    int tens = (num / 10) % 10;
    int ones = num % 10;
    
    if (hundreds == 1) {
        std::print("сто ");
    } else if (hundreds == 2) {
        std::print("двести ");
    } else if (hundreds == 3) {
        std::print("триста ");
    } else if (hundreds == 4) {
        std::print("четыреста ");
    } else if (hundreds == 5) {
        std::print("пятьсот ");
    } else if (hundreds == 6) {
        std::print("шестьсот ");
    } else if (hundreds == 7) {
        std::print("семьсот ");
    } else if (hundreds == 8) {
        std::print("восемьсот ");
    } else if (hundreds == 9) {
        std::print("девятьсот ");
    }
    
    int remainder = num % 100;
    
    if (remainder >= 10 && remainder <= 19) {
        if (remainder == 10) {
            std::print("десять\n");
        } else if (remainder == 11) {
            std::print("одиннадцать\n");
        } else if (remainder == 12) {
            std::print("двенадцать\n");
        } else if (remainder == 13) {
            std::print("тринадцать\n");
        } else if (remainder == 14) {
            std::print("четырнадцать\n");
        } else if (remainder == 15) {
            std::print("пятнадцать\n");
        } else if (remainder == 16) {
            std::print("шестнадцать\n");
        } else if (remainder == 17) {
            std::print("семнадцать\n");
        } else if (remainder == 18) {
            std::print("восемнадцать\n");
        } else if (remainder == 19) {
            std::print("девятнадцать\n");
        }
    } else {
        if (tens == 2) {
            std::print("двадцать ");
        } else if (tens == 3) {
            std::print("тридцать ");
        } else if (tens == 4) {
            std::print("сорок ");
        } else if (tens == 5) {
            std::print("пятьдесят ");
        } else if (tens == 6) {
            std::print("шестьдесят ");
        } else if (tens == 7) {
            std::print("семьдесят ");
        } else if (tens == 8) {
            std::print("восемьдесят ");
        } else if (tens == 9) {
            std::print("девяносто ");
        }
        
        // единицы
        if (ones == 1) {
            std::print("один\n");
        } else if (ones == 2) {
            std::print("два\n");
        } else if (ones == 3) {
            std::print("три\n");
        } else if (ones == 4) {
            std::print("четыре\n");
        } else if (ones == 5) {
            std::print("пять\n");
        } else if (ones == 6) {
            std::print("шесть\n");
        } else if (ones == 7) {
            std::print("семь\n");
        } else if (ones == 8) {
            std::print("восемь\n");
        } else if (ones == 9) {
            std::print("девять\n");
        } else if (ones == 0 && tens == 0) {
            std::print("\n");
        }
    }
    
    return 0;
}