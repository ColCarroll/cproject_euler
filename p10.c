#include <stdlib.h>
#include <stdio.h>
#include "primes.h"

int solve(){
    long upper_bound = 2000000;
    long long tot = 0;
    long i;
    long primes_less_than = 1.2 * prime_number_constant(upper_bound);
    long *prime_array;

    prime_array = malloc(sizeof(long) * primes_less_than);
    long prime_count = primes(&prime_array[0], primes_less_than, upper_bound);

    for(i=0; i<prime_count; i++){
        tot += prime_array[i];
    }

    printf("%llu\n", tot);
    free(prime_array);
    return 0;
}
