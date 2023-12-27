#include <random>
#include <cstdio>
#include <array>

// Generate the alphanumerics

void generate_alphaNum(char* characters) {
    // Generate digits '0' to '9'
    for (int i{}; i < 10; ++i) characters[i] = '0' + i;
    
    // Generate uppercase letters 'A' to 'Z'
    for (int i = 0; i < 26; ++i) characters[i + 10] = 'A' + i;
    
    // Generate lowercase letters 'a' to 'z'
    for (int i = 0; i < 26; ++i) characters[i + 36] = 'a' + i;
}

// Generate the passwords

void generatePass(size_t length, char* chars, size_t passNum) {
    std::random_device rd_engine{};

    std::uniform_int_distribution dist{0,61};

    for (size_t i{}; i < passNum; i++) {
        printf("password#%zd: ",i);

        for (size_t j{}; j < length; j++) {
            size_t index = dist(rd_engine);
            printf("%c",chars[index]);
        }

        printf("\n");
    }
}

int main() {
    size_t passLenght{12};

    char characters[62]{};

    generate_alphaNum(characters);

    size_t n_pass{10};

    generatePass(passLenght, characters, n_pass);
}