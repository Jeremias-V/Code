#include<stdio.h>

int main(){
    int testCases, nCase = 1, nMembers, ageIter, temp;
    scanf("%d", &testCases);
    while(testCases--){
        scanf("%d", &nMembers);
        ageIter = (nMembers/2);
        while(nMembers--){
            scanf("%d", &temp);
            if(nMembers == ageIter){
                printf("Case %d: %d\n", nCase++, temp);
                continue;
            }
        }
    }
    return 0;
}