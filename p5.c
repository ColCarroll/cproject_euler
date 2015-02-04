#include <stdio.h>

int divides_by_all(int n, int up_to){
    int i;
    for(i=2; i <= up_to; i++){
        if(n % i) return 0;
    }
    return 1;
}

int solver(int up_to){
    int j = up_to;
    while(1){
        if(divides_by_all(j, up_to)){
            return j;
        }
        j += up_to;
    }
    return 0;
}

int solve(){
/* 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder. What is the smallest positive number that is
 * evenly divisible by all of the numbers from 1 to 20?
 * */
    printf("%d\n", solver(20));
    return 0;
}
