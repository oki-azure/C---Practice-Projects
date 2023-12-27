// Extended version of the Calculator program from problem 15-5; handles modulo and operator precedence

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

    std::string argument = argv[1]; std::stack<long> numStack; std::stack<char> opStack;

    for (size_t i{}; i < argument.length(); ++i) {
        if ( std::isdigit(argument[i]) ) {
            long num{};

            while ( i < argument.length() && std::isdigit(argument[i])) {
                num = num*10 + (argument[i] - '0');
                ++i;
            }
            
            --i; numStack.push(num);
        }
         
        else if ( argument[i] == '(' ) opStack.push(argument[i]);
                 
        else if (argument[i] == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                char op = opStack.top();

                opStack.pop();

                long num2 = numStack.top();

                numStack.pop();

                long num1 = numStack.top();

                numStack.pop();

                if (op == '+') numStack.push(num1 + num2);
                                 
                else if (op == '-') numStack.push(num1 - num2);                
                
                else if (op == '*') numStack.push(num1 * num2);
                                 
                
                else if (op == '/') {
                    if (num2 == 0) {
                        std::cout << "Division by zero is not allowed." << std::endl;
                        return 1;
                    }

                    numStack.push(num1 / num2);
                } 
                
                else if (op == '%') {
                    if (num2 == 0) {
                        std::cout << "Modulo by zero is not allowed." << std::endl;
                        return 1;
                    }

                    numStack.push(num1 % num2);
                }
            }

            opStack.pop(); // Pop the '('

        } 
        
        else if (argument[i] == '+' || argument[i] == '-' || argument[i] == '*' || argument[i] == '/' || argument[i] == '%') {
            while (!opStack.empty() && opStack.top()!='(' && ((argument[i]=='*' || argument[i]=='/' || argument[i]=='%') ? (opStack.top()=='*' || opStack.top()=='/' || opStack.top()=='%') : (opStack.top()=='*' || opStack.top()=='/' || opStack.top()=='%' || opStack.top()=='+' || opStack.top()=='-'))) {
                // the while loop conditional is using PEMDAS
                char op = opStack.top();

                opStack.pop();

                long num2 = numStack.top();

                numStack.pop();

                long num1 = numStack.top();

                numStack.pop();

                if (op == '+') numStack.push(num1 + num2);        
                
                else if (op == '-') numStack.push(num1 - num2);
                                 
                else if (op == '*') numStack.push(num1 * num2);
                                 
                else if (op == '/') {
                    if (num2 == 0) {
                        std::cout << "Division by zero is not allowed." << std::endl;
                        return 1;
                    }
                                        
                    numStack.push(num1 / num2);
                } 
                
                else if (op == '%') {
                    if (num2 == 0) {
                        std::cout << "Modulo by zero is not allowed." << std::endl;
                        return 1;
                    }                   
                    numStack.push(num1 % num2);
                }
            }

            opStack.push(argument[i]);
        }
    }

    while (!opStack.empty()) {
        char op = opStack.top();

        opStack.pop();

        long num2 = numStack.top();

        numStack.pop();

        long num1 = numStack.top();

        numStack.pop();

        if (op == '+') numStack.push(num1 + num2);
                 
        else if (op == '-') numStack.push(num1 - num2);    
        
        else if (op == '*') numStack.push(num1 * num2);
                 
        else if (op == '/') {
            if (num2 == 0) {
                std::cout << "Division by zero is not allowed." << std::endl;
                return 1;
            }

            numStack.push(num1 / num2);
        } 
        
        else if (op == '%') {
            if (num2 == 0) {
                std::cout << "Modulo by zero is not allowed." << std::endl;
                return 1;
            }
                        
            numStack.push(num1 % num2);
        }
    }

    if (numStack.size() == 1) std::cout << "Result: " << numStack.top() << std::endl;
         
    else std::cout << "Invalid expression" << std::endl;
}