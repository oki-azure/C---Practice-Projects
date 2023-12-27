#pragma once 

// A program the returns the number of factors a given number has

auto numberOfFactors = [](int n) { 
    int factors{2}, i{2}; 

    while (i * i <= n) { 
        if (n % i == 0) { 
            factors += (i * i == n) ? 1 : 2; 

        }   
        
        i++; 
    }   
    
    return factors; 
};
