#include <stdio.h>

int solve(){
    int tot = 0;
    int counter;

    for(counter = 1; counter < 1000; counter++){
        if(counter % 3 == 0 || counter % 5 == 0){
            tot += counter;
        }
    }
    printf("%d\n", tot);
    return 0;
}
