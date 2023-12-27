#include <iostream>
#include <string>
#include <algorithm>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>

using namespace std;
using namespace boost::algorithm;

// A program to count the number of vowels in CLI arguments
 
void countVowels(std::string_view input) {
    size_t count{}; std::string buffer(input);

    to_lower(buffer); replace_all(buffer," ","");    

    for (auto itr = buffer.cbegin(); itr != buffer.cend(); itr++) {
        if (*itr=='a' || *itr=='e' || *itr=='i' || *itr=='o' || *itr=='u') count++;
    }
        
    cout << "Vowel count: " << count;
}

int main(int argc, char** argv) {
    std::string argument; int index{1};

    while (index < argc) {
        argument.append(argv[index]); 
        index++;
    }

    countVowels(argument);
} 