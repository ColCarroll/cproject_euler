#include <stdio.h>

int solve(){
    int old = 1;
    int new = 1;
    int tot = 0;
    int temp;

    while(new < 4000000){
        if (new % 2 == 0){
            tot += new;
        }
        temp = old;
        old = new;
        new = old + temp;
    }
    printf("%d\n", tot);
    return 0;
}
