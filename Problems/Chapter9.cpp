/**********************************************************************************************************************************  
9-1
Implement a fold function template with the following prototype:

template <typename Fn, typename In, typename Out>

constexpr Out fold(Fn function, In* input, size_t length, Out initial);

For example, your implementation must support the following usage:

int main() {
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;
    auto sum = fold([](auto x, auto y) { return x + y; }, data, data_len, 0);
    print("Sum: %d\n", sum);
}
The value of sum should be 1,500. 

Use fold to calculate the following quantities: the maximum, the minimum, and the number of elements greater than 200.
**********************************************************************************************************************************/

#include <cstdio>
#include <cstdint>

/*  
template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, size_t length, Out initial) {
    if (length == 0) return initial; 
    
    else {
        for (size_t index{}; index < length; index++) initial = function(input[index], initial); 
        return initial; 
    }
}

int main() {
    int data[]{100,200,300,400,500}; 
    size_t data_len = 5; 

    auto sum = fold([](auto x, auto y) { return x + y; }, data, data_len, 0); 
    printf("Sum: %d\n", sum); 

    auto max = fold([](auto x, auto y) { auto result  = x > y ? x : y; return result; },data, data_len, data[0]); 
    printf("Maximum: %d\n", max); 

    auto min = fold([](auto x, auto y) { auto result = x < y ? x : y; return result; }, data, data_len, data[0]); 
    printf("Mininum: %d\n", min); 

    int count{}, index{}; 
    auto over200 = fold([&](auto x, auto y) {if (x > 200) ++count; return data[index++];}, data, data_len, 200); 
    printf("over200 count: %zd\n", count); 
}
*/



/******************************************************************************************************************  
9-2
Implement a program that accepts an arbitrary number of command line arguments, 

counts the length in characters of each argument, and prints a histogram of the argument length distribution.
******************************************************************************************************************/

/* 
int main(int argc, char** argv) { 
    int count{}, index{}; 

    printf("Arguments: %d\n", argc); 

    for (size_t i{}; i < argc; i++) printf("%zd: %s\n", i, argv[i]);

    for (int i{}; i < argc; i++) {
        while ( (argv[i])[index] ) {
            count++; 
            index++; 
        }
        
        printf("Argument #%d: ", i); 
        for (int k{}; k < count; k++) printf("*"); 
        printf("\n"); 
        count = 0; index = 0;
    } 
} 
*/


/*****************************************************************************************  
9-3
Implement an all function with the following prototype:

template <typename Fn, typename In, typename Out>
constexpr bool all(Fn function, In* input, size_t length);

The Fn function type is a predicate that supports bool operator()(In). 

Your all function must test whether function returns true for every element of input. 

If it does, return true. Otherwise, return false.

For example, your implementation must support the following usage:
int main() {
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;
    auto all_gt100 = all([](auto x) { return x > 100; }, data, data_len);
    if(all_gt100) printf("All elements greater than 100.\n");
}
*****************************************************************************************/

/*  
template <typename Fn, typename In>
constexpr bool all(Fn fucntion, In* input, size_t length) {
    bool check = true; 

    for (size_t index{}; index < length; index++) {
        check = fucntion(input[index]);
        if (!check) return check;
    }

    return check;
}

int main() {
    int data[]{600, 200, 100, 400, 500}; 

    size_t data_len = 5; 

    auto all_gt100 = all([](auto x) {return x > 100;}, data, data_len); 

    if (all_gt100) printf("All elements are greater than 100"); 
    
    else printf("Not all elements are greater than 100"); 
}
*/