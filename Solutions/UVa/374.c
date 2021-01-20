#include<stdio.h>

unsigned long long expMod(unsigned long long a, unsigned long long n, unsigned long long m){
    if(n == 0){
        return 1%m;
    }
    unsigned long long ans = expMod(a, n/2, m)%m;
    if(n & 1){
        return (ans*ans*(a%m))%m;
    }else{
        return (ans*ans)%m;
    }
}

int main(){
    unsigned long long b, p ,m;
    while(scanf("%lld", &b) != EOF){
        scanf("%lld", &p);
        scanf("%lld", &m);
        printf("%lld\n", expMod(b, p, m));
    }
    return 0;
}