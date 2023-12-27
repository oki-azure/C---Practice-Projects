# include <cstdio>

enum class Operation {
    Add,
    Subtract, 
    Multiply, 
    Divide  
}; 

struct Calculator {
    Calculator(Operation operation)  : operation{operation} {} 

    int calculate(int a, int b) {
        switch (operation) {
            case Operation::Add : {
                answer = a + b; 
                break;
            }
            
            case Operation::Subtract : {
                answer = a - b; 
                break;
            }
            
            case Operation::Multiply : {
                answer = a * b; 
                break;
            }
            
            case Operation::Divide : {
                answer = a / b; 
                break;
            }
            
            default: { printf("Invalid Operation!"); }
        }

        return answer;
    }

    private:
        Operation operation;
        int answer{};
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