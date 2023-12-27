/***************************************************************************************************************************************  
15-1
Refactor the histogram calculator in Listings 9-30 and 9-31 to use std::string. 

Construct a string from the program’s input and modify AlphaHistogram to accept a string_view or a const string& in its ingest method. 

Use a range-based for loop to iterate over the ingested elements of string. 

Replace the counts field’s type with an associative container. 
***************************************************************************************************************************************/

#include <cstdio>
#include <cstdint>
#include <string>
#include <map>
#include <unordered_map>
#include <string_view>

/*  
constexpr char pos_A{ 65 }, pos_Z{ 90 }, pos_a{ 97 }, pos_z{ 122 };

constexpr bool within_AZ(char x) { return pos_A <= x && pos_Z >= x; }

constexpr bool within_az(char x) { return pos_a <= x && pos_z >= x; }

struct AlphaHistogram {
	void ingest(const std::string_view& input);

	void print() const;

    private:
	    std::unordered_map<char, int> counts;
};

void AlphaHistogram::ingest(const std::string_view& input) {
	for (char c : input) {
		if (within_AZ(c)) counts[c]++;
		
		else counts[c - (pos_a - pos_A)]++;
		
	}
}

void AlphaHistogram::print() const {
    for (auto index{pos_A}; index <= pos_Z; index++) {
        printf("%c: ",index);

        if (counts.find(index) != counts.end()) {
            auto n_asterisks = counts.at(index);

            while (n_asterisks--) printf("*");   
        }

        printf("\n");
    }
}

int main(int argc, char** argv) {
    AlphaHistogram hist;

    for (size_t i{1}; i < argc; i++) hist.ingest(argv[i]);

    hist.print();
} 
*/



/***************************************************************************************************************************************  
15-2
Implement a program that determines whether the user’s input is a palindrome.
***************************************************************************************************************************************/

#include <vector>

/* 
bool is_Palindrome(std::string_view word) {
    std::string r_word{word.rbegin(), word.rend()};

    if (r_word == word) return true;

    else return false;
}

int main() {
    std::vector<std::string> words{
        "racecar", "deified", "level", "civic",
        "madam", "noon", "rotor", "tenet", "refer",
        "kayak", "boy"
    };
    
    for (std::string word : words) {
        if (is_Palindrome(word)) printf("%s is a palindrome\n", word.c_str());

        else printf("%s is not a palindrome\n", word.c_str());
    }   
} 
*/



/***************************************************************************************************************************************  
15-3
Implement a program that counts the number of vowels in the user’s input.
***************************************************************************************************************************************/

/* 
std::vector<char> vowels{'a','e','i','o','u'};

size_t vowel_count(std::string_view word) {
    size_t n_vowels{};

    for (char vowel : vowels) {
        for (char c : word) {
            if (tolower(c) == vowel) n_vowels++;
        }
    }
    
    return n_vowels;
}

int main() {
    std::vector<std::string> words{
        "Apple", "Banna", "Elephant",
        "Computer", "Programming", "Sunshine", "Chocolate",
        "Adventure", "Delicious", "Education"
    };

    for (std::string word : words) printf("%s has %zd vowels in it\n", word.c_str(), vowel_count(word));    
} 
*/



/***************************************************************************************************************************************  
15-4
Implement a calculator program that supports addition, subtraction, multiplication, and division of any two numbers. 

Consider using the find method of std::string and the numeric conversion functions.

15-5
xtend your calculator program in some of the following ways: permit multiple operations or the modulo operator and 
accept floating-point numbers or parentheses
***************************************************************************************************************************************/


int main(int argc, char** argv) {
    std::string argument;

    size_t index{1};

    while (index < argc) {
        argument.append(argv[index]);

        index++;
    }

    std::string arg1, arg2;

    using namespace std::string_literals;

    auto operators = "+-*/%"s;

    for (char op : operators) {
        size_t indx = argument.find(op);

        if (indx != std::string::npos) {
            auto itr = argument.begin();

            auto signItr = itr + indx;

            arg1.append(itr, signItr);

            arg2.append((signItr+1), argument.end());

            const auto arg1L = std::stoul(arg1);

            const auto arg2L = std::stoul(arg2);

            switch (op) {
                case '+': {
                    printf("%s + %s = %lu\n", arg1.c_str(), arg2.c_str(), (arg1L + arg2L));
                    break;
                }

                case '-': {
                    printf("%s - %s = %lu\n", arg1.c_str(), arg2.c_str(), (arg1L - arg2L));
                    break;
                }

                case '*': {
                    printf("%s * %s = %lu\n", arg1.c_str(), arg2.c_str(), (arg1L * arg2L));
                    break;
                }

                case '/': {
                    printf("%s / %s = %.1f\n", arg1.c_str(), arg2.c_str(), static_cast<double>( (arg1L / arg2L) ) );
                    break;
                }

                case '%': {
                    printf("%s mod %s = %.1f\n", arg1.c_str(), arg2.c_str(), static_cast<double>( (arg1L % arg2L) ) );
                    break;
                }
                    
                default: printf("Invalid argument");
                   
            }
        }
    }
}