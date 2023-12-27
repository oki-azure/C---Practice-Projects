/*****************************************************************************  
8-1
Refactor Listing 8-27 into separate translation units: one for main and 

another for FibonacciRange and FibonacciIterator. 

Use a header file to share definitions between the two translation units.
*****************************************************************************/

#include "Chapter8.h"
#include <cstdio>

/* 
int main() {
    for (auto i: FibonacciRange{5000}) printf("%d ", i);  
}
*/



/*************************************************************************  
8-2
Implement a PrimeNumberRange class that can be used in a range expression 

to iterate over all prime numbers less than a given value. 

Again, use a separate header and source file.
*************************************************************************/

/* 
int main() {
    printf("--PRIME NUMBERS--"); 

    for (auto i : PrimeNumberRange{5000}) printf("%d ", i);   
} 
*/



/********************************************************************** 
8-3
Integrate PrimeNumberRange into Listing 8-27, adding another loop that 
generates all prime numbers less than 5,000.
**********************************************************************/


int main() {
    printf("---FIBONACCI---\n"); 

    for (auto i: FibonacciRange{5000}) printf("%d ", i); 
    
    printf("\n\n---PRIME NUMBERS---\n"); 

    for (auto i : PrimeNumberRange{5000}) printf("%d ", i); 
}