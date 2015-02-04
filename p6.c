#include <stdio.h>

int sum_of_squares(int n){
    int i;
    int tot = 0;
    for(i=1; i <= n; i++){
        tot += i * i;
    }
    return tot;
}

int square_of_sum(int n){
    int i;
    int tot = 0;
    for(i=1; i <= n; i++){
        tot += i;
    }
    return tot * tot;
}

int solve(){
    int up_to = 100;
    int solution = square_of_sum(up_to) - sum_of_squares(up_to);
    printf("%d\n", solution);
    return 0;
}
