/***************************************************************************************************************************************
16-1 550
Implement an output operator that prints information about the AutoBrake from "An Extended Example: Taking a Brake" on page 284. 

Include the vehicle's current collision threshold and speed.
***************************************************************************************************************************************/

#include <iostream>
using namespace std;

/* 
struct AutoBrake {
    AutoBrake(double collision_threshold, double speed) : collision_threshold_s{collision_threshold}, speed_mps{speed} {}

    double get_collision_threshold() { return collision_threshold_s; }

    double get_speed() { return speed_mps; }

    private:
        double collision_threshold_s;
        double speed_mps;
};

ostream& operator<<(ostream& s, AutoBrake& auto_brake) {
    s << "AutoBrake parameters:\n"

    << "\tcurrent collision threshold/s: " << auto_brake.get_collision_threshold() << "\n"

    << "\tcurrent speed/mps: " << auto_brake.get_speed() << endl;

    return s;
}

int main() {
    AutoBrake autobrake{10, 120};

    cout << autobrake << endl;
}
*/


/***************************************************************************************************************************************
16-2
Write a program that takes input from stdin, capitalizes it, and writes the result to stdout
***************************************************************************************************************************************/

#include <string>
#include <iterator>

/* 
int main() {
    istreambuf_iterator<char> cin_itr{cin.rdbuf()}, end{};

    cout << "Enter a string and i'll capitalize all the words: ";

    string str{cin_itr, end};

    for (char& c : str) {
        if (c >= 65 && c <= 90) continue;

        else c = toupper(static_cast<unsigned char>(c)); // toupper takes an unsigned char, not a char
    }

    cout << str << endl;    
}
*/


/***************************************************************************************************************************************
16-4
Write a program that accepts a file path, opens the file, and prints summary information about the contents, including word word_count, 
average word length, and a histogram of the characters.
***************************************************************************************************************************************/

#include <fstream>
#include <unordered_map>
#include <cstdio>
#include <iomanip>
#include <cmath>

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