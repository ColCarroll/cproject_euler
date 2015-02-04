#include <stdio.h>

int solve() {
    long num = 600851475143;
    long largest_factor = 1;
    long divisor = 3;

    while (num % 2 == 0){
       largest_factor = 2;
       num /= 2;
    }

    while (divisor * divisor <= num){
        while (num % divisor == 0){
            largest_factor = divisor;
            num /= divisor;
        }
        divisor += 2;
    }

    if (num != 1 && num > largest_factor){
        largest_factor = num;
    }

    printf("%lu\n", largest_factor);
    return 0;
}
