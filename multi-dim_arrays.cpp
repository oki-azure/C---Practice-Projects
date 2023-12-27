#include <cstdio>
#include <stdexcept>
#include <cstring>

// Multi-dimensional arrays - arrays of arrays

/****************************************************************************************** 
Can be used to create arrays with visualizations similar to cubes and matrices

Declaration syntax:

type name[size1][size2]...[sizen] ; 


2D arrays:

They're basically a list of arrays(or a table)

Declaration syntax :

type arrayName[row][colum]

the number of elements in the array is row x column

Elements can also be accessed using indices

This time we use 2D indices (arr[i][j])
******************************************************************************************/


// Working with 2D arrays: Declaration


int arr[3][4] = {
    {0,1,2,3} ,
    {4,5,6,7} ,
    {8,9,10,11} 
    // a 3 x 4 array containing 12 elements
} ; 


// Working with 2D arrays: Accessing elements


int main() {
    int arr[5][2] = {
        {1,2}, 
        {3,4}, 
        {5,6}, 
        {7,8}, 
        {9,10}
    } ; 

    int i, j ; 

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]) ; 
        }
    }
}