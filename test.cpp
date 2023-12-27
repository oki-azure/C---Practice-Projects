#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"[expression]\" " << std::endl;
        return 1;
    }

    std::string argument = argv[1];
    std::stack<long> numStack;
    std::stack<char> opStack;

    for (size_t i = 0; i < argument.length(); ++i) {
        if (std::isdigit(argument[i])) {
            // Accumulate digits to form a multi-digit number
            long num = 0;
            while (i < argument.length() && std::isdigit(argument[i])) {
                num = num * 10 + (argument[i] - '0');
                ++i;
            }
            --i; // Move back one step after the last digit

            numStack.push(num);
        } 
        
        else if (argument[i] == '(') {
            opStack.push('(');
        } 
        
        else if (argument[i] == ')') {
            // Process until the matching '('
            while (!opStack.empty() && opStack.top() != '(') {
                // ... (same as before)
            }
            opStack.pop(); // Pop the '('
        } 
        
        else if (argument[i] == '+' || argument[i] == '-' || argument[i] == '*' || argument[i] == '/' || argument[i] == '%') {
            // ... (same as before)
        }
    }

    // Process remaining operators
    while (!opStack.empty()) {
        // ... (same as before)
    }

    if (numStack.size() == 1) {
        std::cout << "Result: " << numStack.top() << std::endl;
    } else {
        std::cout << "Invalid expression" << std::endl;
    }

    return 0;
}