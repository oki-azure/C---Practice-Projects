#include <numeric>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

// A function that mocks the python range function
template <typename T>
vector<T> range(T start, T stop, T step=1) {
    vector<T> result;
    for (T i{start}; i < stop; i += step) result.push_back(i);
    return result;
}

int main() {
    vector<int> numbers{range(1,11)}, results;

    partial_sum(numbers.begin(), numbers.end(), back_inserter(results)); // sum all the numbers in the range

    for (const auto& value : results) cout << value << ", ";

    cout << endl;
}