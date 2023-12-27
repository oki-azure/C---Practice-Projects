// 2-1. Create an enum class Operation that has values Add, Subtract, Multiply, and Divide.

# include <cstdio>

enum class Operation {
    Add,
    Subtract, 
    Multiply, 
    Divide  
}; 


// 2-2. Create a struct Calculator. It should have a single constructor that takes an Operation.

struct Calculator {
    Operation operation; 

    Calculator(Operation operation)  : operation{operation} {} 

    // 2-3. Create a method on Calculator called int calculate(int a, int b). Upon invocation, this method should perform addition, subtraction,
    // multiplication, or division based on its constructor argument and return the result. 

    int calculate(int a, int b) {
        switch (operation) {
            case Operation::Add : {
                return a + b; 
                break;
            }
            
            case Operation::Subtract : {
                return a - b; 
                break;
            }
            
            case Operation::Multiply : {
                return a * b; 
                break;
            }
            
            case Operation::Divide : {
                return a / b; 
                break;
            }
            
            default: {
                printf("Invalid Operation!"); 
            }
        }

    }
};

int main() {
    Calculator add(Operation::Add); 
    int a = 5; 
    int b = 3; 
    int sum = add.calculate(a,b); 
    printf("%d + %d = %d\n", a, b, sum); 

    Calculator sub(Operation :: Subtract); 
    int c = 15; 
    int d = 10; 
    int diff = sub.calculate(c,d); 
    printf("%d - %d = %d\n", c, d, diff); 

    Calculator mul(Operation :: Multiply); 
    int e = 10; 
    int f = 10; 
    int product = mul.calculate(e,f); 
    printf("%d x %d = %d\n", e, f, product); 

    Calculator div(Operation :: Divide); 
    int g = 20; 
    int h = 10; 
    int quotient = div.calculate(g,h); 
    printf("%d / %d = %d", g, h, quotient); 
}