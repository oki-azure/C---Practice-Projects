#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

void fileInfo(std::ifstream&);

int main() {
    cout << "Usage: info [file path]" << endl;

    string command_path;

    getline(cin, command_path); //getline reads an entire line from the stream

    string command(command_path.begin(), command_path.begin() + 4); // info

    string path(command_path.begin() + 5, command_path.end());

    if (command != "info") {
        cout << "Command: " << command << " not found!" << endl;

        return 0;
    }

    else {
        try {
            ifstream file(path.c_str(), ios_base::in);

            if (!file.is_open()) {
                string err{"Unable to open file"};

                err.append("'");

                err.append(path);

                err.append("'");

                throw std::runtime_error{err};
            }

            fileInfo(file);
        }

        catch (const std::exception& e) { cerr << "Error occured: " << e.what() << endl; }
    }
}

void fileInfo(std::ifstream& f) {
    string word;

    size_t word_count{};

    size_t word_lengths{};

    double average_word_length{};

    unordered_map<char, int> word_counts;

    while ( f >> word) {   
        word_count++;

        for (size_t i{}; i < word.length(); i++) {
            if ( (word[i] == ',') || (word[i] == '.') || (word[i] == '?') || (word[i] == '!') ) continue;

            word_lengths++;

            word[i] = tolower(word[i]);

            word_counts[word[i]]++;
        }
    }

    cout << "Discovered " << word_count << " word(s)" << endl;

    average_word_length = static_cast<double>(word_lengths) / word_count; // double / size_t = double, fractional part is maintained

    cout << "Average word length: " << ceil(average_word_length) << endl; // std::ceil runs its argument up

    cout << "Word lengths: " << word_lengths << endl;

    for (auto itr = word_counts.begin(); itr != word_counts.end(); itr++) {
        cout << itr->first << ": ";

        auto element_count = itr->second;

        while (element_count--) printf("*");

        printf("\n");
    }
}
