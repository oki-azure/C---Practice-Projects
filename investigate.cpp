#include <fstream>
#include <unordered_map>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <iostream>

// A program that displays summary info of a file's contents

int main() {
    std::string file_path;

    std::cout << "Enter file path: ";

    std::getline(std::cin, file_path);

    std::ifstream file(file_path);
    
    if (!file.is_open()) {
        std::cout << "Failed to open file\n";
        return 1;
    }

    std::unordered_map<char, int> char_counts;

    std::string word;

    int word_count{}, total_word_length{};

    while (file >> word) {
        ++word_count;
        
        for (char c : word) {
            ++char_counts[c];

            if (std::isalpha(c)) total_word_length++;
        }
    }

    double average_word_length = static_cast<double>(total_word_length) / word_count;

    std::cout << "Discovered: " << word_count << " words" << std::endl;

    std::cout << "Total word length: " << total_word_length << std::endl;

    std::cout << "Average word length: " << std::ceil(average_word_length) << std::endl;

    std::cout << "Character histogram:\n";

    for (const auto& pair : char_counts) std::cout << pair.first << ": " << std::string(pair.second, '*') << "\n";
}