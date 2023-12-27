// A program to determine if CLI argument is a palindrome

#include <string>
#include <iostream>
#include <string_view>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>

using namespace std;
using namespace boost::algorithm;
 
void isPalindrome(std::string_view input) {
    auto begin = input.crbegin(); auto end = input.crend();

    std::string r_input(begin, end);

    to_lower(r_input); replace_all(r_input," ","");

    if (r_input == input) cout << input.data() << " is a palindrome" << endl;

    else cout << input.data() << " isn't a palindrome" << endl;
}

int main(int argc, char** argv) {
    std::string input;

    int index{1};

    while (index < argc) {
        input.append(argv[index]);
        index++;
    }

    isPalindrome(input);
} 