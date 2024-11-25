#include <stdio.h>
#include <math.h>
double findSquareRoot(double n) {
    if (n == 0 || n == 1) {
        return n; 
    }  
    double low = 0, high = n, mid;
    double precision = 0.0001; 
    
    while (high - low > precision) {
        mid = low + (high - low) / 2;
        
        if (mid * mid == n) {
            return mid; 
        }
        else if (mid * mid < n) {
            low = mid;  
        } else {
            high = mid;  
        }
    }
    return (low + high) / 2; 
}
int main() {
    double number = 25.0;
    double result = findSquareRoot(number);
    
    printf("Square root of %.2f is approximately %.4f\n", number, result);
    
    return 0;
}
