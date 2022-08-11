#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10000000

int main(){
    unsigned *ans = (unsigned*)malloc(sizeof(unsigned)*MAX);
    unsigned i;
    ans[0] = 1;
    double accum = 0;
    for(i = 1; i <= MAX; i++){
        accum += log10(i);
        ans[i] = accum+1;
    }
    unsigned testCases, input;
    scanf("%u", &testCases);
    while(testCases--){
        scanf("%u", &input);
        printf("%u\n", ans[input]);
    }
    return 0;
}