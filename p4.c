#include <stdio.h>
#include <string.h>

int is_palindrome(int n){
    char nstr[7];
    int i = 0;
    sprintf(nstr, "%d", n);
    int len = strlen(nstr);
    for(i = 0; i < strlen(nstr) / 2; i++){
        if(nstr[i] != nstr[len - i - 1]){
            return 0;
        }
    }
    return 1;
}

int solve(){
    int i = 1;
    int j = 1;
    int prod = 1;
    int max_prod = 1;
    for(i=1; i < 1000; i++){
        for(j=i; j < 1000; j++){
            prod = i * j;
            if(prod > max_prod && is_palindrome(prod)){
                max_prod = prod;
            }
        }
    }
    printf("%d\n", max_prod);
    return 0;
}
