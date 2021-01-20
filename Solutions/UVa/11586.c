#include<stdio.h>
#define MAX 1000
int main(){
    int testCases, loop, i, fiter = 1, fNumber, mNumber;
    char trainTrack[MAX];
    scanf("%d", &testCases);
    while(testCases--){
        fNumber = 0;
        mNumber = 0;
        loop = 1;
        if(fiter){
            while ((getchar()) != '\n');
            fiter = 0;
        }
        fgets(trainTrack, MAX, stdin);
        for(i = 0; i < MAX; i++){
            if(trainTrack[i] == '\n' || trainTrack[i] == '\0'){
                break;
            }
            if(trainTrack[i] == 'M'){
                ++mNumber;
            }
            if(trainTrack[i] == 'F'){
                ++fNumber;
            }
            
        }
        if(fNumber == mNumber && fNumber > 1 && mNumber > 1){
            printf("%s", "LOOP\n");
        }else{
            printf("%s", "NO LOOP\n");
        }
    }
    return 0;
}