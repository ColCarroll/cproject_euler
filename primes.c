#include <math.h>
#include <stdio.h>

int is_prime(int n){
    int i;

    if(n == 2) return 1;

    if(!(n % 2)) return 0;

    for(i = 3; i * i <= n; i += 2){
        if(!(n % i)){
            return 0;
        }
    }
    return 1;
}

float prime_number_constant(long n){
    /* Returns number of primes less than n */
    return n / log(n);
}

long solve_monotone_func(float (*func)(long), long equals){
    long solution = 0;
    long step = 1;
    int direction = (*func)(solution) < equals ? 1 : -1;

    while(direction * (*func)(solution) < direction * equals) {
        step *= 2;
        solution = direction * step;
    }

    while(step > 1){
        direction *= -1;
        step /= 2;
        while(direction * (*func)(solution) < direction * equals) {
            solution += direction * step;
        }
    }
    return solution;
}

int number_of_divisors(long n){
    int num_divisors = 1;
    int multiplier = 1;
    while(!(n % 2)){
        num_divisors += 1;
        n /= 2;
    }

    int p = 3;

    while(p * p <= n){
        multiplier = 1;
        while(!(n % p)){
            multiplier += 1;
            n /= p;
        }
        num_divisors *= multiplier;
        p += 2;
    }

    if(n > 1){
        num_divisors *= 2;
    }
    return num_divisors;
}

long primes(long *primes, long prime_len, long numbers_to_check){
    int numbers[numbers_to_check];
    long i, j;
    long prime_count = 0;

    for(i=0; i<numbers_to_check; i++){
        numbers[i] = 1;
    }

    for(i=2; i<numbers_to_check; i++){
        if(numbers[i]){
            primes[prime_count++] = i;

            if(prime_count == prime_len) break;

            for(j=i; i+j<numbers_to_check; j+=i){
                numbers[i + j] = 0;
            }
        }
    }
    return prime_count;
}

void first_n_primes(long *prime_array, long n){
    long numbers_to_check = solve_monotone_func(prime_number_constant, n);
    primes(&prime_array[0], n, numbers_to_check);
}

