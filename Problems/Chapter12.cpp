/***************************************************************************************************************************************  
12-1
Reimplement the narrow_cast in Listing 6-6 to return a std::optional. 

If the cast would result in a narrowing conversion, return an empty optional rather than throwing an exception. 

Write a unit test that ensures your solution works
***************************************************************************************************************************************/

#include <catch2/catch_all.hpp>

/*   
template <typename To, typename From>
std::optional<To> narrow_cast(From value) {
    const auto converted = static_cast<To>(value);

    const auto backwards = static_cast<From>(converted);

    if (value != backwards) return std::nullopt;

    return converted;
}

TEST_CASE("Conversion works") {
    int perfect{496};
    auto perfect_short = narrow_cast<short>(perfect);

    int cyclic{142857};
    auto cyclic_short = narrow_cast<short>(cyclic);

    if (perfect_short) REQUIRE(perfect_short.value() == perfect);
    else FAIL("Narrowed!");
    
    if (cyclic_short) FAIL("Error!");

    REQUIRE_FALSE(cyclic_short.has_value());
}
*/


/***************************************************************************************************************************************  
12-2
Implement a program that generates random alphanumeric passwords and writes them to the console. 

You can store the alphabet of possible characters into a char[] and use the discrete uniform distribution with a minimum of zero and a 

maximum of the last index of your alphabet array. 

Use a cryptographically secure random number engine.
***************************************************************************************************************************************/

#include <random>
#include <cstdio>
#include <array>

// Generate the alphanumerics

/*  
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
*/