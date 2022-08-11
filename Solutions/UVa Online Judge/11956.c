#include<stdio.h>
#include<string.h>
int main(){
    int testCases, i, j, currentPos, count = 1;
    char input, bytes[100][2];
    scanf("%d", &testCases);
    getchar();
    while(testCases--){
        for(i = 0; i < 100; i++){
            for(j = 0; j < 2; j++){
                bytes[i][j] = (char)48;
            }
        }
        //memset(bytes, 48, sizeof(bytes[0][0]) * 100 * 2);
        currentPos = 0;
        input = getchar();
        while(input != '\n'){
            switch(input){
                case '>':
                currentPos++;
                currentPos = (currentPos > 99) ? (currentPos-100) : currentPos;
                break;
                case '<':
                currentPos--;
                currentPos = (currentPos < 0) ? (currentPos+100) : currentPos;
                break;
                case '+':
                bytes[currentPos][1]++;
                if(bytes[currentPos][1] > 57 && bytes[currentPos][1] < 65){
                    bytes[currentPos][1] += 7;
                }
                if(bytes[currentPos][1] > 70){
                    bytes[currentPos][1] = 48;
                    bytes[currentPos][0]++;
                }
                if(bytes[currentPos][0] > 57 && bytes[currentPos][0] < 65){
                    bytes[currentPos][0] += 7;
                }
                if(bytes[currentPos][0] > 70){
                    bytes[currentPos][1] = 48;
                    bytes[currentPos][0] = 48;
                }
                break;
                case '-':
                bytes[currentPos][1]--;
                if(bytes[currentPos][1] < 48){
                    bytes[currentPos][1] = 70;
                    bytes[currentPos][0] -= 1;
                }
                if(bytes[currentPos][1] > 57 && bytes[currentPos][1] < 65){
                    bytes[currentPos][1] -= 7;
                }
                if(bytes[currentPos][0] < 48){
                    bytes[currentPos][0] = 70;
                }
                if(bytes[currentPos][0] > 57 && bytes[currentPos][0] < 65){
                    bytes[currentPos][0] -= 7;
                }
                break;
            }
            input = getchar();
        }
        printf("Case %d: ", count++);
        for(i = 0; i < 100; i++){
            if(i != 99){
                printf("%c%c ", bytes[i][0], bytes[i][1]);
            }else{
                printf("%c%c", bytes[i][0], bytes[i][1]);
            }
            
        }
        printf("%c", '\n');
    }
    return 0;
}