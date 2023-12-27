#include <set>
#include <cstdio>
#include <algorithm>
#include <array>
#include <cstring>
#include <string>

// A program that sorts CLI arguments 

struct CStrComparator {
    bool operator()(const char* str1, const char* str2) const {
        // Convert strings to lowercase before comparison
        std::array<char, 256> lowerStr1;
        std::array<char, 256> lowerStr2;

        std::strcpy(lowerStr1.data(), str1);
        std::strcpy(lowerStr2.data(), str2);

        for (char* p = lowerStr1.data(); *p; ++p) *p = std::tolower(static_cast<unsigned char>(*p));
        for (char* p = lowerStr2.data(); *p; ++p) *p = std::tolower(static_cast<unsigned char>(*p));
        
        return std::strcmp(lowerStr1.data(), lowerStr2.data()) < 0;
    }
};

int main(int argc, char** argv) {
    // Create a set with the custom comparator
    std::set<const char*, CStrComparator> argSet;

    // Skip the first argument, the program name
    for (size_t i{1}; i < argc; i++) argSet.insert(argv[i]);

    // Print the sorted arguments
    for (const char* arg : argSet) std::puts(arg);
}