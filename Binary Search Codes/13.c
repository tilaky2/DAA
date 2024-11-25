#include <stdio.h>

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        printf("Error: Division by zero\n");
        return -1;
    }
    if (dividend == 0) {
        return 0;
    }
    int negative = (dividend < 0) ^ (divisor < 0); 
    dividend = (dividend < 0) ? -dividend : dividend;
    divisor = (divisor < 0) ? -divisor : divisor;

    int low = 0, high = dividend, result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (divisor * mid <= dividend) {
            result = mid;  
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return negative ? -result : result;
}

int main() {
    int dividend = 10;
    int divisor = 3;

    int quotient = divide(dividend, divisor);
    printf("Quotient of %d / %d is: %d\n", dividend, divisor, quotient);

    return 0;
}
