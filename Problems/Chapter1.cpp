/**************************************************************************************************  
1-1
Create a function called absolute_value that returns the absolute value of its single argument. 

The absolute value of an integer x is the following: x (itself)

if x is greater than or equal to 0; otherwise, it is x times −1. 

You can use the program in Listing 1-9 as a template:
**************************************************************************************************/


#include <cstdio>

int absoulte_value(int x) {
    if (x > 0) return x; 

    else if (x < 0) return x * -1; 
    
    else return 0; 
}

int main() {
    int num  = -1002; 
    
    printf("The absolute value of %d, is: %d", num, absoulte_value(num));
}