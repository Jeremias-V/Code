#include<stdio.h>

int main(){
    int nFront, nRear, i, j, k;
    double temp, max;
    scanf("%d", &nFront);
    while(nFront > 0){
        scanf("%d", &nRear);
        int fTeeth[nFront], rTeeth[nRear];
        for(i = 0; i < nFront; i++){
            scanf("%d", fTeeth+i);
        }
        for(i = 0; i < nRear; i++){
            scanf("%d", rTeeth+i);
        }
        double quotient[nFront*nRear];
        k = 0;
        for(i = 0; i < nFront; i++){
            for(j = 0; j < nRear; j++){
                quotient[k++] = (double)rTeeth[j] / (double)fTeeth[i];
            }
        }
        for(i = 0; i < nFront*nRear; i++){
            for(j = 1; j < nFront*nRear; j++){
                if(quotient[j] < quotient[j-1]){
                    temp = quotient[j-1];
                    quotient[j-1] = quotient[j];
                    quotient[j] = temp;
                }
            }
        }
        max = 0.0;
        for(i = 1; i < nFront*nRear; i++){
            temp = quotient[i]/quotient[i-1];
            max = temp > max ? temp : max;
        }
        printf("%.2f\n", max);
        scanf("%d", &nFront);
    }
    return 0;
}