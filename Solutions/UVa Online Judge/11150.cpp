#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        cout << (n&1 ? (((3*n)+1)/2)-1 : ((3*n)+1)/2) << endl;   
    }
    return 0;
}