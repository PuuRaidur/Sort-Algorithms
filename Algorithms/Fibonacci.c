#include <stdio.h>
int fib(){
    int result, a, b, i;
    a = 0;
    b = 1;
    i = 1;
    while(i <= 20){
        printf("%d\t", a);
        result = a + b;
        a = b;
        b = result;
        i++;
    }
}
void main(){
    fib();
}