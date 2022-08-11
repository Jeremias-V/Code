#include<stdio.h>
#include<string.h>

struct Car{
    char name[100];
    unsigned int low, high;
};

int main(){
    short testCases;
    unsigned int carNum, query, price, i, count, min, max;
    struct Car dataCar[10000];
    char tempName[100];
    scanf("%hd", &testCases);
    while(testCases--){
        min = 10000000;
        max = 0;
        scanf("%u", &carNum);
        for(i = 0; i < carNum; i++){
            scanf("%s %u %u", dataCar[i].name, &dataCar[i].low, &dataCar[i].high);
            min = (dataCar[i].low < min) ? dataCar[i].low : min;
            max = (dataCar[i].high > max) ? dataCar[i].high : max;
        }
        scanf("%u", &query);
        while(query--){
            count = 0;
            scanf("%u", &price);
            if(price >= min && price <= max){
                for(i = 0; i < carNum; i++){
                    if(dataCar[i].low <= price && dataCar[i].high >= price){
                        count++;
                        if(count > 1) break;
                        strcpy(tempName, dataCar[i].name);
                    }
                }
            }
            if(count == 1){
                printf("%s\n", tempName);
            }else{
                printf("UNDETERMINED\n");
            }
        }
        if(testCases > 0){
            printf("\n");
        }   
    }
    return 0;
}