/***************************************************************************************************************************************  
14-1
Create a corollary to Listing 14-8 using std::prev rather than std::next.
***************************************************************************************************************************************/

#include <iterator>
#include <catch2/catch_all.hpp>

/* 
TEST_CASE("next and prev returns iterators at given offsets") {
    std::vector<unsigned char> mission {
        0x9e, 0xc4, 0xc1, 0x29,
        0x49, 0xa4, 0xf3, 0x14,
        0x74, 0xf2, 0x99, 0x05,
        0x8c, 0xe2, 0xb2, 0x2a 
    };

    auto itr1 = mission.begin();
    std::advance(itr1, 4);
    REQUIRE(*itr1 == 0x49);

    auto itr2 = std::prev(itr1);
    REQUIRE(*itr2 == 0x29);

    auto itr3 = std::prev(itr1, 4);
    REQUIRE(*itr3 == 0x9e);

    REQUIRE(*itr1 == 0x49);
}  
*/


/***************************************************************************************************************************************  
14-2
Write a function template called sum that accepts a half-open range of 

int objects and returns the sum of the sequence.
***************************************************************************************************************************************/

#include <cstdio>
#include <vector>
using namespace std;

/* 
template <typename T>
int sum(T objects) {
    int result{};

    for (auto object : objects) result += object;

    return result;
}

int main() {
    std::vector<int> range{37, 89, 12, 64, 25, 53, 6, 71, 44, 98};

    printf("Sum: %d\n", sum(range));
} 
*/



/***************************************************************************************************************************************  
14-3
Write a program that uses the Stopwatch class in Listing 12-25 to determine the runtime performance of std::advance when given a 

forward iterator from a large std::forward_list and a large std::vector. 

How does the runtime change with the number of elements in the container? 
(Try hundreds of thousands or millions of elements.)
***************************************************************************************************************************************/

#include <chrono>
#include <forward_list>
#include <random>

struct Stopwatch {
    Stopwatch(std::chrono::nanoseconds& result) : result{result}, start{std::chrono::high_resolution_clock::now()} {}

    ~Stopwatch() { result = std::chrono::high_resolution_clock::now() - start; }

    private:
        std::chrono::nanoseconds& result;
        const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

// A function to generate a number of random longs within a uniform int distribution
// of range 0-1000 

long random() {
    static std::mt19937_64 mt_engine{1027};

    static std::uniform_int_distribution<long> int_d{0, 1000};

    return int_d(mt_engine);
}

int main() {
    std::chrono::nanoseconds elapsed;
    size_t n{1'000'000};

    std::vector<long> vec(n);
    std::forward_list<long> f_list(n);

    std::generate(vec.begin(), vec.end(), random);
    std::generate(f_list.begin(), f_list.end(), random);

    // Large Vector Traversal
    {
        Stopwatch duration{elapsed};

        auto itr = vec.begin();

        while (itr != vec.end()) std::advance(itr,1);

        printf("Large Vector Traversal Duration: %lldns\n", (elapsed.count()/n));
    }

    // Large F_list Traversal
    {
        Stopwatch duration{elapsed};

        auto itr = f_list.begin();

        while (itr != f_list.end()) std::advance(itr,1);

        printf("Large F_list Traversal Duration: %lldns\n", (elapsed.count() / n));
    }
  
}