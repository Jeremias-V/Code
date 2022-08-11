#include<stdio.h>
#include<vector>
using namespace std;

int main(){
    int nChimps, nQuery, currentQ, i, max, min, mid, temp, last = -1;
    vector<int> hChimps;
    scanf("%d", &nChimps);
    for(i = 0; i < nChimps; i++){
        scanf("%d", &temp);
        if(temp != last) hChimps.push_back(temp);
        last = temp;
    }
    scanf("%d", &nQuery);
    for(i = 0; i < nQuery; i++){
        scanf("%d", &currentQ);
        min = 0;
        max = hChimps.size()-1;
        if(currentQ <= hChimps[min]){
            if(currentQ < hChimps[min]) printf("X %d\n", hChimps[min]);
            if(currentQ == hChimps[min]) printf("X %d\n", hChimps[min+1]);
        }else if(currentQ >= hChimps[max]){
            if(currentQ > hChimps[max]) printf("%d X\n", hChimps[max]);
            if(currentQ == hChimps[max]) printf("%d X\n", hChimps[max-1]);
        }else{
            while(min <= max){
                mid = min + (max - min)/2;
                if(hChimps[mid] == currentQ){
                    printf("%d %d\n", hChimps[mid-1], hChimps[mid+1]);
                    break;
                }
                if(hChimps[mid] < currentQ){
                    min = mid + 1;
                }else{
                    max = mid - 1;
                }
                if(max == min - 1){
                    printf("%d %d\n", hChimps[max], hChimps[min]);
                    break;
                }
            }
        }
    }
    return 0;
}