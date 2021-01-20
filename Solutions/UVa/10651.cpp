#include<iostream>
#include<string>

using namespace std;

unsigned pCount;

int min(int a, int b){
    return (a < b) ? a : b;
}

int pebbleSolve(unsigned n, string input){
    pCount = min(pCount, n);
    for(int i = 0; i < input.size(); i++){
        if(i+2 < input.size() && input[i] == 'o' && input[i+1] == 'o' && input[i+2] == '-'){
            input[i] = '-', input[i+1] = '-', input[i+2] = 'o';
            pebbleSolve(n-1, input);
            input[i] = 'o', input[i+1] = 'o', input[i+2] = '-';
        }
        if(i-2 >= 0 && input[i] == 'o' && input[i-1] == 'o' && input[i-2] == '-'){
            input[i] = '-', input[i-1] = '-', input[i-2] = 'o';
            pebbleSolve(n-1, input);
            input[i] = 'o', input[i-1] = 'o', input[i-2] = '-';
        }
    }
    return pCount;
}

int main(){
    unsigned testCases;
    string input;
    cin >> testCases;
    while(testCases--){
        cin >> input;
        pCount = 0;
        for(int i = 0; i < input.size(); i++) if(input[i] == 'o') pCount++;
        cout << pebbleSolve(pCount, input) << endl;
    }
    return 0;
}