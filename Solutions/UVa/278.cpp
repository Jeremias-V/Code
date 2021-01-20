#include<iostream>
using namespace std;

int main(){
    unsigned testCases, m, n;
    char piece;
    cin >> testCases;
    while(testCases--){
        cin >> piece >> m >> n;
        if(piece == 'r') cout << ((m < n) ? m : n) << endl;
        else if(piece == 'k') cout << (((m*n)/2) + ((m*n)%2)) << endl;
        else if(piece == 'Q') cout << ((m < n) ? m : n) << endl;
        else if(piece == 'K') cout << (((m + m%2)*(n + n%2))/4) << endl;
    }
    return 0;
}