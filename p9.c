#include <stdio.h>
#include "primes.h"

int solve(){
    int a, b, c;
    int b_limit;
    int upper_limit = 1000;
    int a_limit = (int)(upper_limit / 3);
    for(a=1; a<a_limit; a++){
        b_limit = (int)((upper_limit - a) / 2);
        for(b=a+1; b<b_limit; b++){
            c = upper_limit - a - b;
            if(a * a + b * b == c * c){
                printf("%d\n", a * b * c);
                return 0;
            }
        }
    }
    return 0;
}
