#include<stdio.h>

int main(){
    int testCases, i, j, input[19], caseNum = 1;
    long long int max, iter;
    while(scanf("%d", &testCases) != EOF){
        for(i = 0; i < testCases; i++){
            scanf("%d", &input[i]);
        }
        max = 0;
        iter = 1;
        for(i = 0; i < testCases; i++){
            for(j = i; j < testCases; j++){
                iter*= input[j];
                max = (iter > max) ? iter : max;
            }
            iter = 1;
        }
        printf("Case #%d: The maximum product is %lli.\n\n", caseNum++,max);
        max = 0;
    }
    return 0;
}