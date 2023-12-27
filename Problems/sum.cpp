# include <cstdio>

int sum(int x, int y) {
    return x + y ; 
}


int main() {
    int num1 = 403 ; 

    int num2 = 2003 ; 

    printf("%d + %d = %d", num1, num2, sum(num1, num2)) ; 
}