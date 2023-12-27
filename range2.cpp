// another program that mocks the python range function

#include <iostream>
#include <numeric>
#include <array>

using namespace std;

int main() {
    array<int,100> numbers;

    iota(numbers.begin(), numbers.end(), 1);

    for (const auto& number : numbers) {
        if (number == *(numbers.end()-1)) cout << number << endl;
        else cout << number << ", ";
    }
}