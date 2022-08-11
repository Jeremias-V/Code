#include<stdio.h>

int main(){
    int H1, M1, H2, M2, totalM;
    scanf("%d %d %d %d", &H1, &M1, &H2, &M2);
    while(H1 || M1 || H2 || M2){
        totalM = 0;
        while(M1 != M2 || H1 != H2){
            totalM++;
            M1++;
            if(M1 > 59){
                M1 = 0;
                H1++;
            }
            if(H1 > 23){
                H1 = 0;
            }
        }
        printf("%d\n", totalM);
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);
    }
    return 0;
}