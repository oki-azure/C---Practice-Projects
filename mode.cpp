#include <cstdio>

// A program that finds the mode of a data set
 
template <typename T>
T mode(const T* values, size_t length) {
    if (length == 0) return 0; 

    int max{},  amount{},  max_index{}; 

    for (size_t i{}; i < length; i++) {
        T cursor = values[i]; 

        amount++; 

        for (size_t j = i + 1; j < length; j++) {
            if (cursor == values[j]) amount++; 
        }

        if (amount > max) {
            max = amount; 

            max_index = i; 

            amount = 0; 
        }

        else if (amount < max) {
            amount = 0; 

            continue; 
        }

        else if (amount == max) return 0; 
    }

    return values[max_index]; 
}

int main() {
    short test[] = {1,1,1,2,2,2,2,4,5,1,4,4,6,6,6,6,1,1,1,6,6,6,6,5,6,6,5,5,5,5};

    size_t length = sizeof(test) / sizeof(short); 

    printf("Array: "); 

    for (size_t i = 0; i < length; i++) {
        printf("%hd ", test[i]); 
    }

    printf("\nMode is: %hd", mode(test, length)); 
}