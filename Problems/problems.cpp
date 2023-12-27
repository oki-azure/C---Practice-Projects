/*******************************************************************************************  
1.  Introduce yourself

We need to create a simple introduction application.

Create an application that will just print your introduction on the output screen such

as your name and your hobbies.
*******************************************************************************************/

#include <cstdio>

/* 
int main() {
    char name[20]{}, hobbies[50]{} ;

    int age{} ; 

    printf("What is your name?:\n") ; 

    scanf("%s", &name) ;

    printf("How old're you?:\n") ; 

    scanf("%d", &age) ;  

    printf("What do you do when you're free?:\n(Provide a single action word)\n") ; 

    scanf("%s", &hobbies) ; 

    printf("\n\nWelcome %s!\nYou're %d years old\nYou %s when you're free\n", name, age, hobbies) ; 
} 
*/


/******************************************************************************************  
2.  Bounce Back
As the name suggests, do we need to create a bouncing ball game? Of course not!

The problem is simple, we need to create an application that will accept the favorite

number of the user and simply print it back on the output screen.

Just like a bounced back ball from a wall.
******************************************************************************************/


/* 
int main() {
    int fav_num = {} ; 

    printf("What is your favourite number?:\n") ; 

    scanf("%d", &fav_num) ; 

    printf("\nYoure favourite number is: %d", fav_num) ; 
} 
*/




/*******************************************************************************  
3.  Age Calculator 
We need to calculate the age of the user.

Accept the birth year of the user from them and calculate the age of the user

accordingly and display it out the output screen.

Time for some math!
*********************************************************************************/


/* 
int main() {
    int birthYear{}, currentYear{} ; 

    printf("Give me your birth year and i'll tell you your age\n") ; 

    printf("Birth year:\n") ; 

    scanf("%d", &birthYear) ; 

    printf("What year is it?:\n") ; 

    scanf("%d", &currentYear) ; 

    birthYear -= currentYear ; // I'm not proud of it either

    int age{-birthYear} ; // please allow

    printf("As of %d, you're %d years old!", currentYear, age) ;  
} 
*/


/****************************************************************  
4.  Percentage
Find the percentage of the user in an exam.

Accept the marks scored by the user and also the total marks. 

Thus, find and print the percentage scored by the user.

Back to school!
****************************************************************/


/* 
int main() {
    int marks[8]{}, sum{} ; 

    float percentage{} ; 

    printf("Tell me your scores in all your eight WASCCE courses\n") ; 

    for (size_t i{}; i < 8; i++) {
        printf("Course #%zd: ",i) ; 

        scanf("%d",&marks[i]) ; 
    }

    for (int i : marks) {
        sum += i ; 
    }

    percentage = (sum/8) ; 

    char sign{'%'} ; 

    printf("You had %.0f%c  in WASSCCE\nCongrats!!", percentage, sign) ; 

} 
*/


/***************************************************************************************  
5.  Convert Temperature
Write a program to convert the temperature from Celsius to Fahrenheit.

Accept the temperature in Celsius from the user and convert it to the Fahrenheit and
print it to the output screen.

Convertor though!
*****************************************************************************************/


/* 
int main() {
    float celcius{} ;

    printf("Give me a temperature reading in Celcius and i'll convert it to Farenheit\n") ; 
    
    printf("Celcius:\n") ; 

    scanf("%f",&celcius) ;  

    float fahrenheit  = (celcius * 9/5) + 32 ; 

    printf("%.0f in Farenheit is: %.0f", celcius, fahrenheit) ; 
} 
*/


/***************************************************************************************  
6.  Average
The problem is to find the average marks of a student in three subjects.

We need to create a program that will accept the marks of the user in three subjects
and return the average marks scored by the user.

Let's get started.
****************************************************************************************/

/* 
int main() {
    int marks[3]{}, sum{} ; 

    printf("\nGive me your scores in three subjects and i'll return your average\n") ; 

    for (size_t i{}; i < 3; i++) {
        printf("Subject#%zd: ",i) ; 

        scanf("%d", &marks[i]) ; 
    }

    for (int i : marks) {
        sum += i ; 
    }

    float avg = sum / 3 ; 

    printf("Your average in all three courses is:%.2f", avg) ; 
} 
*/





/***********************************************************************************  
7.  Swap Time
Write a program to swap two numbers.

Create a simple program that will accept two numbers from the user and swap them.

Sounds exciting? Let's start.
***********************************************************************************/


/* 
int main() {
    int x{}, y{} ; 

    printf("\nGive me two numbers and i'll swap them\n") ; 

    printf("First number:\n") ;

    scanf("%d",&x) ; 

    printf("Second number:\n") ; 

    scanf("%d",&y) ; 

    x = x ^ y ^ (y = x) ;  // XOR to the rescue!

    printf("\nBeep...Beep...Beep\n") ; 

    printf("First number is now: %d\n", x) ; 

    printf("And second number is now: %d", y) ; 

    printf("\n\nBooyah!!!!") ; 
    
} 
*/



/*************************************************************  
8.  Square root

Write a program to find the square root of the numbers.

Accept the number from the user and return the square root.

Time to recall cmath!
*************************************************************/

#include <cmath>

/* 
int main() {
    int num{} ; 

    printf("\nGive me a number an i'll square root it:\n") ; 

    scanf("%i", &num) ; 

    printf("Sqaure root of %d is: %.1f", num, sqrt(num)) ; 

} 
*/


/*****************************************************************************************  
9.  Simple Interest
Write a program to calculate the Simple Interest for your user.

Accept the principal amount, rate of interest, and time from the user, calculate the
simple interest and return the value.

Interesting? 
*****************************************************************************************/

/* 
int main() {
    float si{}, principal{}, rate{}, time{}, amount{} ;

    printf("----Simple Interest Calculator----\n") ; 

    printf("Principal: \n") ; 

    scanf("%f", &principal) ;

    printf("Rate: \n") ; 

    scanf("%f", &rate) ; 

    printf("Time: \n") ; 

    scanf("%f", &time) ;

    printf("---Beep...Beep...Beep---\n") ; 

    si = (principal * rate * time)/100 ; 

    amount += (principal + si) ;  

    printf("Simple Interest is: $%.2f\n", si) ;  

    printf("In %.1f years, you'll pay $%.2f\n", time, amount) ; 

    printf("----Simple Interest Calculator----\n") ;
     
} 
*/


/*****************************************************************************************  
10. Area of a Circle
Create a program to find the area of a circle.

Write a program that will accept the radius of a circle from the user, and return its
area.

Time for some Geometry!
*****************************************************************************************/


/* 
int main() {
    float radius{}, area{} ; 

    printf("\nGive me the radius of a circle and i'll tell you its area\n") ;

    printf("Radius:\n") ; 

    scanf("%f", &radius) ; 

    double pi = 2*acos(0) ; // the value of pi

    area = pi * (radius*radius) ;  

    printf("The locus of points %.1fcm from a fixed point enclose an area of %.4fsqcm", radius, area) ; 
} 
*/



/****************************************************************************************  
11. Area of a rectangle
Write a program to find the area of a rectangle.

Accept the length and the breath of the rectangle from the user and find the area of
the rectangle.

Pretty simple, right?
****************************************************************************************/

/* 
int main() {
    float length{}, breadth{}, area{} ;

    printf("\nGive me the length and breadth of a Rectangle and i'll tell you it's area\n") ; 

    printf("Length x Breadth: ") ; 

    scanf("%fx%f", &length, &breadth) ; 

    area = length * breadth ; 

    printf("\nThe area of a rectangle %.2fcm x %.2fcm is: %.4fsqd-cm", length, breadth, area) ;  
} 
*/



/*************************************************************************  
12. Algebra - Factors of a Number
Write a program to find the factors of a number.

Accept a number from the user and find all the factors of that number.

Time for some algebra!

*************************************************************************/


/* 
int main() {
    int num{} ; 

    printf("\nGive me a number and i'll tell you all its factors\n") ; 

    printf("Number: ") ; 

    scanf("%d", &num) ; 

    int* factors = new int[num] ; // use a dynamic array to init a flexible array

    size_t index{} ; 

    for (int i{1}; i < (num + 1); i++) {
        if (num % i == 0) {
            factors[index] = i ; 

            index++ ; 

        }
    }

    printf("The factors of %d are:\n", num) ; 

    for (size_t j{}; j < index; j++) printf("%d\n", factors[j]) ; 

    delete[] factors ;  
} 
*/



/*************************************************************************  
13. Even or Odd

Write a program to find whether a number is even or odd.

Accept a number from the user, and print whether it is even or odd.

Time for using conditionals in this section!
*************************************************************************/

/* 
int main() {
    int num{} ; 

    printf("\nGive me a number and i'll tell you if it's even or odd\n") ; 

    printf("Number: ") ; 

    scanf("%d", &num) ; 

    if (num % 2 == 0) printf("Even\n") ; 

    else printf("Odd") ; 
} 
*/


/*****************************************************************************************  
14. Bank Balance

Write a program for the bank withdrawal system.

Accept the bank balance and the withdrawal amount from the user.

If the bank balance is greater than the withdrawal amount, then allow a successful
withdrawal with an appropriate message.

Else show the error message.
*****************************************************************************************/

/* 
int main() {
    float balance{}, withdrawal{} ;

    printf("\n----Bank of Sogakope----\n") ; 

    printf("Enter account balance: ") ; 

    scanf("%f", &balance) ; 

    printf("\nEnter amount to withdraw ") ; 

    scanf("%f", &withdrawal) ;

    if (balance >= withdrawal) {
        balance -= withdrawal ; 

        printf("Transaction Successful\n") ; 

        printf("Current Balance: $%.2f\n", balance) ; 

    }

    else printf("Transaction Unsuccessful due to insufficient funds\n") ; 

    printf("\n----Bank of Sogakope----\n") ;
} 
*/


/****************************************************************************  
15. The Largest

Write a program to find the largest number among the three numbers.

Accept three numbers from the user and determine the largest among them.

Sounds simple?
****************************************************************************/

/* 
int main() {
    int nums[3]{}, max{} ; 

    printf("\nGive me three numbers and i'll tell you which is the largest\n") ; 

    printf("Enter three numbers(x,y,z): ") ; 

    scanf("%d,%d,%d",&nums[0], &nums[1], &nums[2]) ; 

    for (size_t i{}; i < 3; i++) {
        if (nums[i] > max) max = nums[i] ; 

    }

    printf("The largest is: %d", max) ; 
} 
*/


/**********************************************************************************  
16. Calculator 

Write a program to create a calculator.

Accept the operator from the user for which they wish to perform the operation.

Accordingly, perform the operation and return the value.

Time to Calculate!
**********************************************************************************/


/* 
int main() {
    char sign;

    int num1{}, num2{}, result{} ; 

    printf("Let's Calculate\n") ; 

    printf("Enter operator(+,-,*,/): ") ; 

    scanf("%c", &sign) ; 

    printf("\nEnter operands(x,y): ") ; 

    scanf("%d,%d",&num1, &num2) ; 

    switch (sign) {
        case '+' : {
            result = num1 + num2 ; 

            break;
        }

        case '-' : {
            result = num1 - num2 ;
            
            break;  
            
        }

        case '*' : {
            result = num1 * num2 ; 

            break;
        }

        case '/' : {
            result = num1 / num2 ; 

            break;
        }

        default : {
            printf("Error! Operator unknown\n") ; 
        }

        
    }

    printf("\nResult: %d", result) ; 
} 
*/


/*************************************************************************************  
17. Multiplication table

Write a program to generate the multiplication table up to 10 for a given number.

Accept a number from the user and return its multiplication table.

Back to school? Huh!
*************************************************************************************/

/* 
int main() {
    int num{} ;
    
    printf("----The Times Table----\n") ; 

    printf("Give me a number and i'll return its times table\n") ;

    printf("Enter Number: ");

    scanf("%d", &num) ;  

    printf("\n") ; 

    for (int i{1}; i < 11; i++) {
        printf("%d x %d = %d\n", num, i, (num*i)) ; 
    }

    printf("----The Times Table----\n") ;
} 
*/


/************************************************************************************  
18. Sum of Numbers

Write a program to find the sum of the natural numbers.

Accept a number from the user and return the sum of all the numbers starting from
one to the number entered by the user.

For example, if the value entered by the user is 5, then the result should be
5+4+3+2+1=15.
****************************************************************************************/

/* 
int main() {
    int num{}, sum{}; 

    printf("Give me an number and i'll return its sum to 1\n"); 

    printf("Enter Number: "); 

    scanf("%d", &num); 

    for (num; num > 0; num--) sum += num;     

    printf("\nSum to 1: %d", sum); 
} 
*/


/********************************************************************************  
20. Prime

Write a program to check whether a number is a prime number or not.

Accept the number from the user and determine whether it is prime.

A prime number is a positive integer that is divisible only by 1 and itself. 

For example: 2,3, 5, 7, 11, 13, 17
***************************************************************************************/

/* 
int main() {
    int num{}, index{}; 

    printf("\nGive me a number and i'll tell you if it's prime or not\n"); 

    printf("Enter the number: "); 

    scanf("%d", &num); 

    int* factors = new int[num];

    for (int i{1}; i <= num; i++) {
        if (num % i == 0) {
            factors[index] = i; 

            index++;
        }           
    } 

    if (index == 2) printf("\nIt's prime"); 

    else printf("\nNot prime!"); 

    delete[] factors; 
} 
*/


/**************************************************************************  
21. Factorial

Write a program to find the factorial of a number.

Accept the number from the user and return the factorial of that number.
**************************************************************************/


/* 
int main() {
    int num{}, product{1} ; 

    printf("\nGive me a number and i'll return its factorial\n") ; 

    printf("Enter Number: ") ; 

    scanf("%d", &num) ;

    if (num < 0 ) {
        printf("Negative numbers don't factorial!") ; 

        return 0 ; // exit early
    } 

    for (int i{num}; i > 0; i--) product *= i ; 
    
    printf("\n%d! is: %d", num, product) ; 
} 
*/

// OR 

#include <cstdint>

/* 
uint32_t factorial(uint32_t number) {
    return number <= 1 ? number : factorial(number - 1) * number ; 
}

int main() {
    uint32_t num{}, result{} ; 

    printf("\nGive me a number and i'll return its factorial\n") ; 

    printf("Enter Number: ") ; 

    scanf("%u", &num) ;

    result = factorial(num) ; 

    printf("\n%u! is: %u", num, result) ;
}
*/


/*********************************************************************  
22. Largest in Array

Write a program to find the largest element in an array.

Create an array and fill the array with the user input. 

Then find the largest element of the array and return the output.

Time to work with arrays!
*********************************************************************/


/* 
int main() {
    int nums[10]{}, max{} ;

    printf("\nGive me a bunch of numbers and i'll tell you which is the largest\n") ; 

    for (size_t i{}; i < 10; i++) {
        printf("#%zd: ", i) ; 

        scanf("%d", &nums[i]) ; 
    }

    printf("\nBeep...Beep...Beep\n") ; 

    for (int i{}; i < 10; i++) {
        if (nums[i] > max) max = nums[i] ; 
    }

    printf("\nThe largest is: %d", max) ;  
} 
*/



/******************************************************************************************  
23. String Stats

Write a program to find the length of a string.

Create a program that will return the length of the given string, you cannot use any
built-in method to do that.

Ready?
******************************************************************************************/


/* 
int main() {
    char* string[100]{} ;

    size_t counter{} ;  

    printf("\nGive me a string and i'll return its length\n") ; 

    printf("String: ") ; 

    fgets(string, sizeof(string), stdin) ;

    for (size_t i{}; i < 99; i++) {
        if (string[i] != '\0' && string[i] != ' ' && string[i] != '\n') {
            counter++ ;
        };

        // C-style strings are not delicate, so they must be handled thoroughly
    }

    printf("The string is %zd characters long", counter) ; 
} 
*/



/****************************************************************************  
24. Matrix Addition

Write a program to add two matrices.

Accept two matrices from the user and return the resultant added matrix.

Time to level up!
****************************************************************************/


/* 
int main() {
    printf("\n----Matrix Addition----\n") ; 

    int rows, columns, MatA[10][10], MatB[10][10], MatAns[10][10], i, j ;

    printf("Enter the number of rows: ") ;

    scanf("%d", &rows) ; 

    printf("Enter the number of columns: ") ; 

    scanf("%d", &columns) ; 

    // Build MatA

    printf("\nEnter the elements of MatA:\n") ; 

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("Enter the element A%d%d: ", i+1, j+1) ; 

            scanf("%d", &MatA[i][j]) ; 
        }
    }  

    // Build MatB

    printf("\nEnter the elements of MatB:\n") ;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("Enter the element B%d%d: ", i+1, j+1) ; 

            scanf("%d", &MatB[i][j]) ; 
        }
    } 

    // add the two matrices

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            MatAns[i][j] = MatA[i][j] + MatB[i][j] ; 
        }
    } 

    // output result to console

    printf("\nMatA + MatB: \n") ; 

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d  ", MatAns[i][j]) ;             
        }

        printf("\n") ; 
    } 
} 
*/