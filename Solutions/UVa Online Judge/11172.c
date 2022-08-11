#include<stdio.h>

int main(){
    int testCases, n1, n2;
    scanf("%d", &testCases);
    while(testCases--){
        scanf("%d %d", &n1, &n2);
        if(n1 > n2) printf(">\n");
        else if(n1 < n2) printf("<\n");
        else printf("=\n");
    }
    
    return 0;
}