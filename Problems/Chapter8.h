#pragma once
#include <cstdint>

// 8-1

struct FibonacciIterator {
    bool operator!=(int x) const { return x >= current; }

    FibonacciIterator& operator++() {
        const auto tmp = current; 
        current += last; 
        last = tmp; 
        return *this; 
    }

    int operator*() const { return current; }

    private:
        int current{1}, last{1}; 
};

struct FibonacciRange {
    explicit FibonacciRange(int max) : max{max} {}

    FibonacciIterator begin() const { return FibonacciIterator{}; }

    int end() const { return max; }

    private:
        const int max; 
};


// 8-2

struct PrimeNumberIterator {
    bool operator!=(int x) const { return x >= current; }

    PrimeNumberIterator& operator++() {
        current++; 

        do {
            for (size_t i = 2; i < current; i++) {
                if (current % i == 0) {
                    current++; 
                    i = 2; 
                }
            }

            break;

        } while (true); 
        
        return *this; 
    }

    int operator*() const { return current; }

    private:
        int current{2}; 

        bool flag{true}; 
   
};

struct PrimeNumberRange {
    explicit PrimeNumberRange(int max) : max{max} {}

    PrimeNumberIterator begin() const { return PrimeNumberIterator{}; }

    int end() const { return max; }

    private:
        const int max; 
};