#include<stdio.h>

struct URL{
    char URL[102];
    unsigned int rel;
};

int main(){
    unsigned int testCases, i, max, numCase = 1;
    struct URL urls[10]; 
    scanf("%u", &testCases);
    while(testCases--){
        max = 0;
        for(i = 0; i < 10; i++){
            scanf("%s %u", urls[i].URL, &urls[i].rel);
            max = (urls[i].rel > max) ? urls[i].rel : max;
        }
        printf("Case #%u:\n", numCase++);
        for(i = 0; i < 10; i++){
            if(urls[i].rel == max){
                printf("%s\n", urls[i].URL);
            }
        }
    }
    return 0;
}