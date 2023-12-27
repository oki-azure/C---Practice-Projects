// Write a program to create a 5-line right-angle triangle star pattern

#include <iostream>

int main() {
    for (int i{}, j{1}; i < 15; i++) {
        while(j <= i+1) {
            std::cout << "*";

            j++;
        }

        std::cout << std::endl;

        j = 1;
    }
}