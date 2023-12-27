/***************************************************************************************************************************************
Write a program to check whether a number is a palindrome or not.
Create a program that checks if a number is a palindrome, accept the number from the user. 
Handle the result with a proper message.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* 
int main() {
    cout << "Give me a number and let's see if it's a palindrome or not!" << endl;

    size_t digit_size{};
    
    cout << "Size of number: ";

    std::cin >> digit_size;

    vector<int> digits;

    cout << "Enter the digits of the number in turns:" << endl;
    
    for (size_t i{}; i < digit_size; i++) {
        int num{};
        
        std::cin >> num;

        digits.push_back(num);
    }

   vector<int> reversed_digits(digits.crbegin(), digits.crend());

   cout << "Original number is : ";
   
   for (const auto& digit : digits) cout << digit;

   cout << "\nNumber in reverse is: ";

   for (const auto& digit : reversed_digits) cout << digit;

   if (digits == reversed_digits) cout << "\nSo it's a palindrome!" << endl;

   else cout << "\nSo it's not a palindrome!" << endl;
} 
*/

// OR 

int main() {
    int temp{}, num{}, digit, rev{};

    cout << "Give me a number and let's see if its a palindrome!: ";

    cin >> num; temp = num;

    do { digit = num % 10; rev = (rev*10) + digit; num /= 10; }

    while (num != 0);

    cout << "Original number: " << temp << "\nNumber in reverse is: " << rev << endl;

    if (temp == rev) cout << "So " << rev << " is a palindrome!" << endl;

    else cout << temp << " is not a palindrome!" << endl;
}