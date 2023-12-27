#include <cstdio>

/********************************************************************************************************  
6-1
The mode of a series of values is the value that appears most commonly.

Implement a mode function using the following signature: int mode(const int* values, size_t length). 

If you encounter an error condition, such as input having multiple modes and no values, return zero
********************************************************************************************************/

/*  
int mode(const int* values, size_t length) {
    if (length == 0) return 0; 

    int max{}, amount{}, max_index{}; 

    for (size_t i{}; i < length; i++) {
        int cursor = values[i]; 
        
        amount++; 

        for (size_t j{i + 1}; j < length; j++) {
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
    int data_set[] = {1,1,1,2,2,2,2,4,5,1,4,4,6,6,6,6,1,1,1,6,6,6,6,5,6,6,5,5,5,5};

    size_t length = sizeof(data_set) / sizeof(int); 

    printf("Array: "); 

    for (size_t i = 0; i < length; i++) printf("%d ", data_set[i]); 
    
    printf("\nMode is: %d", mode(data_set, length)); 
} 
*/



/******************************************  
6-2
Implement mode as a template function
******************************************/

/*  
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
*/


/******************************************************************************************* 
6-4
Refactor mean in Listing 6-13 to accept an array rather than pointer and length arguments. 

Use Listing 6-33 as a guide.
*******************************************************************************************/

/*  
template <typename T, size_t Length>
T mean(T (&arr)[Length]) {
    T result{}; 

    for (size_t i{}; i < Length; i++) result += arr[i]; 
    
    return result / Length; 
}

int main() {
    double nums_d[]{1.0, 2.0, 3.0, 4.0};
	auto result1 = mean(nums_d);
	printf("double array mean: %.1f\n", result1);

	float nums_f[]{1.0f, 2.0f, 3.0f, 4.0f};
	auto result2 = mean(nums_f);
	printf("float array mean: %.1f\n", result2);

	size_t nums_c[]{1, 2, 3, 4, 5, 6, 7, 8};
	auto result3 = mean(nums_c);
	printf("size_t array mean: %zd\n", result3);
}
*/



/**************************************************************************************  
6-5 
Using the example from Chapter 5, make Bank a template class that

accepts a template parameter. Use this type parameter as the type of an 

account rather than long. Verify that your code still works using a Bank<long>class
**************************************************************************************/

/*  
struct ConsoleLogger {
    void log_transfer(long from, long to, double amount) { printf("%ld -> %ld: %.2f\n", from, to, amount); }
};

template <typename T>
struct Bank {
    void make_transfer(T from, T to, double amount) { logger.log_transfer(from, to, amount); }

    ConsoleLogger logger; 
};

int main() {
    Bank <long>bank; 

    bank.make_transfer(1000, 2000, 49.85); 

    bank.make_transfer(2004, 4008, 20.00); 
}
*/



/**************************************************************************  
6-6
Implement an Account class and instantiate a Bank<Account>. 

Implement functions in Account to keep track of balances.

6-7.
Make Account an interface. 

Implement a CheckingAccount and SavingsAccount. 

Create a program with several checking and savings accounts. 

Use a Bank<Account> to make several transactions between the accounts.
**************************************************************************/

/*  
struct Account {
    virtual void setBalance(double amount) = 0; 

    virtual void getBalance() const = 0; 

    const char* accountName; 

    double accountBalance; 
};

struct CheckingAccount : Account {
    CheckingAccount(const char* name) {
        accountName = name; 

        accountBalance = 10000; 
    }

    void setBalance(double amount) override { accountBalance += amount; }

    void getBalance() const override { printf("\nBalance in %s: $%.2f", accountName, accountBalance); }
};

struct SavingsAccount : Account {
    SavingsAccount(const char* name) {
        accountName = name; 

        accountBalance = 10000; 
    }

    void setBalance(double amount) override { accountBalance += amount; }

    void getBalance() const override { printf("\nBalance in %s: $%.2f", accountName, accountBalance); }
    
};

template <typename T>
struct Bank {
    void make_transfer(T& from, T& to, double amount) {
        to.setBalance(amount); 

        from.accountBalance -= amount; 

        printf("\n%s -> %s :: $%.2f", from.accountName, to.accountName, amount); 
    }
};

int main() {
    CheckingAccount check01{"Aure"}; 

    CheckingAccount check02{"Stan"}; 

    CheckingAccount check03{"Buzz"}; 

    SavingsAccount save01{"Abz"}; 

    SavingsAccount save02{"Yaz"}; 

    SavingsAccount save03{"Han"}; 

    Bank<Account> bank; 

    printf("---TRANSFERS---"); 

    bank.make_transfer(check01, check02, 10000); 

    bank.make_transfer(check03, check01, 1000); 

    bank.make_transfer(check02, check03, 10000); 

    bank.make_transfer(check03, check02, 10000); 

    printf("\n\n---BALANCE---"); 

    check01.getBalance(); 

    check02.getBalance(); 

    check03.getBalance(); 

    save01.getBalance(); 

    save02.getBalance(); 

    save03.getBalance() ;
}
*/