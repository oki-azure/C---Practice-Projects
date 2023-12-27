/***************************************************************************************************************************************
Write a program to find the largest number among the three numbers.
Accept three numbers from the user and determine the largest among them.
***************************************************************************************************************************************/

#include <iostream>
#include <array>

int main() {
    int max{};

    std::array<int,3> nums;

    std::cout << "Give me three numbers and i'll tell you the greatest:" << std::endl;

    for (size_t i{}; i < 3; ++i) std::cin >> nums[i];

    for (auto& num : nums) {
        if (num > max) max = num;
    }

    std::cout << "The greatest is " << max << std::endl;
}