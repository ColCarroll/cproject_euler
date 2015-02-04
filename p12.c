#include <stdio.h>
#include "primes.h"

int min_triangle_divisors(int divisors){
    int tri_number = 1;
    int step = 2;
    int max_divisors = 1;
    int tri_divisors;
    int max_tri = 1;
    while(max_divisors <= divisors){
        tri_number += step;
        step += 1;
        tri_divisors = number_of_divisors(tri_number);
        if(tri_divisors > max_divisors){
            max_divisors = tri_divisors;
            max_tri = tri_number;
        }
    }
    return max_tri;
}


int solve(){
    printf("%d\n", min_triangle_divisors(500));
    return 0;
}
