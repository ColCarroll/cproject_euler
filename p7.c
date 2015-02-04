#include <stdio.h>
#include "primes.h"

int solve(){
    long num_primes = 10001;
    long prime_nums[num_primes];
    first_n_primes(&prime_nums[0], num_primes);
    printf("%lu\n", prime_nums[num_primes - 1]);
    return 0;
}
