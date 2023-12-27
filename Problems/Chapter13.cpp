/***************************************************************************************************************************************  
13-1
Write a program that default constructs a std::vector of unsigned longs.

Print the capacity of vector and then reserve 10 elements. 

Next, append the first 20 elements of the Fibonacci series to the vector. 

Print capacity again. 

Does capacity match the number of elements in the vector? Why or why not? 

Print the elements of vector using a range-based for loop.
***************************************************************************************************************************************/

#include <cstdio>
#include <vector>
#include <array>
#include <catch2/catch_all.hpp>

using namespace std;

// A function to generate a vector of the first n Fibonacci numbers

  
std::vector<int> FibonacciGenerator(const size_t n) {
    std::vector<int> resultVector{1};
    size_t result{}, previous{}, current{1};

    for (size_t i{}; i < n-1; i++) {
        result = previous + current;
        resultVector.emplace_back(result);
        previous = current;
        current = result;
    }

    return resultVector;
}


/* 
TEST_CASE("Vector Capacity Test") {
    std::vector<unsigned long> vec_of_lus;

    printf("Vector Capacity: %d\n", vec_of_lus.capacity());

    vec_of_lus.reserve(10);

    printf("Vector Capacity After Reservation: %d\n", vec_of_lus.capacity());

    auto fib_vec = FibonacciGenerator(20); 

    vec_of_lus.assign(fib_vec.begin(), fib_vec.end());

    printf("Vector Capacity After Assignment: %d\n", vec_of_lus.capacity());

    REQUIRE(vec_of_lus.capacity() == vec_of_lus.size());
    // Yes, the capacity of the vector matches its size

    for (auto element : vec_of_lus) printf("%lu ", element);
}
*/


/***************************************************************************************************************************************  
13-2
Rewrite Listings 2-9, 2-10, and 2-11 in Chapter 2 using std::array.
***************************************************************************************************************************************/

/* 
int main() {
    printf("----Listing 2-9----\n");
    std::array<int, 4> arr{1,2,3,4};
    printf("The third element is %d\n", arr[2]);
    arr[2] = 100;
    printf("The third element is now %d\n", arr[2]);

    printf("\n\n----Listing 2-10----\n");
    unsigned long max{};
    std::array<unsigned long, 5> values{10, 50, 20, 40, 0};
    {   
        for (size_t i{}; i < 5; i++) if (values[i] > max) max = values[i];
        printf("The maximum value is %lu\n", max);
    }

    printf("\n\n----Listing 2-11----\n");
    {   
        for (unsigned long value : values) if (value > max) max = value;
        printf("The maximum value is %lu\n", max);
    }
}
*/


/***************************************************************************************************************************************  
13-3
Write a program that accepts any number of command line arguments and prints them in alphanumerically sorted order. 

Use a std::set<const char*> to store the elements, then iterate over the set to obtain the sorted result. 

You’ll need to implement a custom comparator that compares two C-style strings.
***************************************************************************************************************************************/

#include <set>

// Custom comparator for C-style strings

/*  
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
*/

/***************************************************************************************************************************************  
The strcmp function compares characters lexicographically, which means it considers the ASCII values of characters. 

In the ASCII character set, uppercase letters come before lowercase letters. 

Hence "I" will come before "came" in the lexicographical order, as 'I' has a lower ASCII value (73) than 'c' (99).

To sort words in a case-insensitive manner, so "came" comes before "I", the custom comparator is modified to convert the strings to

lowercase before comparing them
***************************************************************************************************************************************/



/***************************************************************************************************************************************  
13-5 & 13-6
Consider the following program that profiles the performance of a function summing a Fibonacci series
***************************************************************************************************************************************/


#include <chrono>
#include <random>

/*  
long fib_sum(size_t n) { 
    auto fibVec = FibonacciGenerator(n);

    long sum{};

    for (auto element : fibVec) return sum += element;

    return 0;
}

long random() { 
    static std::mt19937_64 mt_engine{102787};

    static std::uniform_int_distribution<long> int_d{1000, 2000};

    return int_d(mt_engine);
}

struct Stopwatch { 
    Stopwatch(std::chrono::nanoseconds& result): result{result}, start{std::chrono::system_clock::now()} {}

    ~Stopwatch() { result = std::chrono::system_clock::now() - start; }

    private: 
        std::chrono::nanoseconds& result;
        const std::chrono::time_point<std::chrono::system_clock> start;
};

long cached_fib_sum(const size_t& n) { 
    static std::map<long, long> cache;

    if (cache.find(n) == cache.end()) { //  key does not exist
        auto sum = fib_sum(n);

        cache.insert({n, sum});

        return sum;
    }

    else return cache[n]; // key exists

    return 0;
}

int main() {
    size_t samples{ 1'000'000 };

    std::chrono::nanoseconds elapsed;

    {
        Stopwatch stopwatch{elapsed};

        volatile double answer;

        while(samples--) {
           //answer = fib_sum(random()); 

           answer = cached_fib_sum(random()); 
        }
    }

    printf("Elapsed: %gs.\n", elapsed.count() / 1'000'000'000.); 
}
*/

/***************************************************************************************************************************************  
This program contains a computationally intensive function fib_sum that computes the sum of a Fibonacci series with a given length. 

Adapt your code from Exercise 13-1 by 
(a) generating the appropriate vector and 
(b) summing over the result with a range-based for loop. 

The random function returns a random number between 1,000 and 2,000, and the Stopwatch class  adopted from Listing 12-25 in Chapter 12 
helps you determine elapsed time. 

In the program’s main, you perform a million evaluations of the fib_sum function using random input . 

You time how long this takes and print the result before exiting the program 
{Compile the program and run it a few times to get an idea of how long your program takes to run}
(This is called a baseline.)


13-6
Next, comment out  and uncomment . Implement the function cached_fib_sum  so you first check whether you’ve computed fib_sum for the given 
length yet. (Treat the length n as a key into the cache.) 

If the key is present in the cache, simply return the result. 

If the key isn’t present, compute the correct answer with fib_sum, store the new key-value entry into cache, and return the result. 

Run the program again. Is it faster? 

Try unordered_map instead of map. 

Could you use a vector instead?

How fast can you get the program to run?
***************************************************************************************************************************************/

// computing the sum with the map container resulted in much much faster computation than
// plainly using the 'fib_sum' function.





/***************************************************************************************************************************************  
13-7
Implement a Matrix class like SquareMatrix in Listing 13-38. 

Your Matrix should allow unequal numbers of rows and columns. 

Accept as your constructor’s first argument the number of rows in Matrix. 
***************************************************************************************************************************************/

#include <initializer_list>
#include <stdexcept>

/*  
template <typename T>
struct UnevenMatrix {
    UnevenMatrix(size_t rows, std::initializer_list<T> vals) : rows{rows}, data{rows, std::vector<T>{}} {
        auto itr = vals.begin();

        size = vals.size();

        columns = size / rows;

        for (size_t row{}; row < rows; row++) {
            data[row].assign(itr, (itr+columns));

            itr += columns;
        }
    }

    T& at(size_t row, size_t col) {
        if ( (row >= rows) || (col >= columns) ) throw std::out_of_range{"Index invalid"};
    
        return data[row][col];
    }

    void print() {
        for (size_t i{}; i < rows; i++) {
            for (size_t j{}; j < columns; j++) printf("%d ", data[i][j]);
            
            printf("\n");
        }

        printf("\n");
    }

    size_t size, rows, columns;

    private:
        std::vector<std::vector<T>> data;
};

TEST_CASE("Rectangular Matrix") {
    UnevenMatrix<int> matA{ 3,
        {   1, 2,
            3, 4,
            5, 0,
        }
    }; 

    matA.print();

    matA.at(2,1) = 6;

    REQUIRE(matA.at(2,1) == 6);

    REQUIRE(matA.columns == 2);

    matA.print();
}

TEST_CASE("Square Matrix") {
    UnevenMatrix<int> matB{ 3, 
        {
            1, 2, 3,
            4, 5, 0,
            7, 0, 1,
        }
    };

    matB.print();

    matB.at(1,2) = 6;

    matB.at(2,1) = 8;

    matB.at(2,2) = 9;

    REQUIRE(matB.at(1,2) == 6);

    REQUIRE(matB.at(2,1) == 8);

    REQUIRE(matB.at(2,2) == 9);

    REQUIRE(matB.rows == matB.columns);

    matB.print();
}
*/