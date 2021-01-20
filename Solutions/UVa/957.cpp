#include<iostream>
using namespace std;

int main(){
    unsigned int period, nPopes, i, lefti, righti, popeCount, max, lastLeft, lastRight;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(cin >> period){
        cin >> nPopes;
        unsigned int popes[nPopes];
        for(i = 0; i < nPopes; i++){
            cin >> popes[i];
        }
        lefti = 0;
        popeCount = 1;
        max = 0;
        righti = 0;
        lastLeft = 0;
        lastRight = 0;
        for(i = 1; i < nPopes; i++){
            if(popes[i] - popes[lefti] < period){
                popeCount++;
                righti = i;
            }else{
                if(popeCount > max){
                    max = popeCount;
                    lastLeft = lefti;
                    lastRight = righti;
                }
                if(popes[i] - popes[lefti] >= period && lefti + 1 < nPopes){
                    lefti++;
                }
            }
        }
        if(lefti < 1){
            cout << popeCount << " " << popes[0] << " " << popes[nPopes-1] << "\n";
        }else{
            cout << max << " " << popes[lastLeft] << " " << popes[lastRight] << "\n";
        }
    }
    return 0;
}