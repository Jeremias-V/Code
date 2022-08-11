#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100000

int main(){
    unsigned int testCases, money = 0, i, size;
    char donations[MAX], num[MAX], input, *trash;
    long readInt;
    scanf("%d", &testCases);
    getchar();
    while(testCases--){
        fgets(donations, MAX, stdin);
        size = strlen(donations);
        if(size > 7){
            for(i = 7; i < size; i++){
                num[i-7] = donations[i];
            }
            readInt = strtol(num, &trash, 10);
            money += readInt;
        }else{
            printf("%d\n", money);
        }
    }
    return 0;
}