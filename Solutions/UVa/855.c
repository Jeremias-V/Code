#include<stdio.h>

void sort(int *arr, int n){
    int key, i, j;
    for(j = 1; j < n; j++){
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i -= 1;
        }
        arr[i+1] = key;
    }
}

int main(){
    int testCases, street, avenue, friends, i;
    scanf("%d", &testCases);
    while(testCases--){
        scanf("%d %d %d", &street, &avenue, &friends);
        int streets[friends], avenues[friends];
        for(i = 0; i < friends; i++){
            scanf("%d %d", &streets[i], &avenues[i]);
        }
        sort(streets, friends);
        sort(avenues, friends);
        if(friends & 1){
            printf("(Street: %d, Avenue: %d)\n", streets[(friends/2)], avenues[(friends/2)]);
        }else{
            printf("(Street: %d, Avenue: %d)\n", streets[(friends/2)-1], avenues[(friends/2)-1]);
        }
        
    }
    return 0;
}