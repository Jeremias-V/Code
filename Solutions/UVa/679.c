#include <stdio.h>

int main(){
    int cases, I, D, i, ans;
    scanf("%d", & cases);
    while(cases--){
        scanf("%d %d", &D, &I);
        ans = 1;
        for(i = 0; i < D-1; i++){
            if(I&1){
                I = (I+1)/2;
                ans = ans * 2;
            }else{
                ans = (ans * 2) + 1;
                I = I / 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
