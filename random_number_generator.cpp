#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

long random() {
    static std::mt19937_64 mt_engine{1027};

    static std::uniform_int_distribution<long> int_d{0, 10};

    return int_d(mt_engine);
}

int main() {
    size_t n{10};

    std::vector<long> numbers(n);

    std::generate(numbers.begin(), numbers.end(), random);

    for (const auto& number : numbers) {
        if ( number == *(numbers.end()-1) ) std::cout << number << std::endl;
        
        else std::cout << number << ", ";
    }
}