// This program times the runtime of a program

#include <iostream>
#include <chrono>

using namespace std;

struct Stopwatch {
    Stopwatch(std::chrono::nanoseconds& result) : result{result}, start{std::chrono::high_resolution_clock::now()} {}

    ~Stopwatch() { result = std::chrono::high_resolution_clock::now() - start; }

    private:
        std::chrono::nanoseconds& result;

        const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

int main() {
    chrono::nanoseconds time_taken; // any other time literal could be used

    int n{1};

    // Wrap the execution code in this scope to time it 
    {
        Stopwatch stopwatch{time_taken};
        
        for (int i = 0; i < 10'000'000; i++) n = (n*i*i) % 2021;
    }
    
    cout << "Operation Completed Successfully\n" << "Took approximately: " << time_taken.count() / 1.0E9 << " ns" << endl;
}