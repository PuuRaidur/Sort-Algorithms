#include <stdio.h>

int fun(int n){
    if(n==0){
        return 1;
    }
    else{
        return fun(n-2) + 7;
    }
}
void main(){
    printf("%d", fun(4));
}
// still can't understand why it's 15