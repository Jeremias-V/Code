/*
La complejidad de esta solución es de O(n)
porque sin contar la lectura de datos, su
procesamiento se hace en dos recorridos
lineales.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool comp(unsigned a, unsigned b){
    return a > b;
}

int main(){
    unsigned testCases, input, total;
    vector<unsigned> landCost;
    cin >> testCases;
    while(testCases){
        total = 0;
        cin >> input;
        while(input != 0){
            landCost.push_back(input);
            cin >> input;
        }
        sort(landCost.begin(), landCost.end(), comp);
        for(int i = 0; i < landCost.size(); i++){
            total += 2*pow(landCost[i], i+1);
            if(total > 5000000){
                cout << "Too expensive" << endl;
                break;
            }
        }
        if(total <= 5000000) cout << total << endl;
        landCost.clear();
        testCases--;
    }    
    return 0;
}