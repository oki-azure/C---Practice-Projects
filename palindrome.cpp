#include <cstdio>
#include <string>
#include <string_view>
#include <vector>

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