#include<stdio.h>
#include<string.h>

int main(){
    int result[5] = {56, 96, 36, 76, 16}, size;
    short testCases;
    char temp[999999];
    scanf("%hd", &testCases);
    while(testCases--){
        scanf("%s", temp);
        size = strlen(temp);
        if(size < 2){
            if(temp[0] == 48){
                printf("1\n");
            }else if(temp[0] == 49){
                printf("66\n");
            }else{
                printf("%d\n", result[(temp[size-1])%5]);
            }
        }else{
            printf("%d\n", result[(temp[size-1])%5]);
        }
    }
    return 0;
}