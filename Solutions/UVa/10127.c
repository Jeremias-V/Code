#include<stdio.h>

unsigned multiple(unsigned n, unsigned m, unsigned i){
    if((m % n) == 0) return i;
    else multiple(n, ((m * 10) + 1)%n, i+1);
}

int main(){
    unsigned n, m, i;
    while(scanf("%u", &n) != EOF){
        printf("%u\n", multiple(n, 1, 1));
    }
    return 0;
}