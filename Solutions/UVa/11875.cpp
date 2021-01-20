#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int testCases, teamMembers[11], nMembers, count = 1, member, key, i, j;
    cin >> testCases;
    while(testCases--){
        cin >> nMembers;
        for(i = 0; i < nMembers; i++){
            cin >> teamMembers[i];
        }
        for(j = 1; j < nMembers; j++){
            key = teamMembers[j];
            i = j-1;
            while(i >= 0 && teamMembers[i] > key){
                teamMembers[i+1] = teamMembers[i];
                i -= 1;
            }
            teamMembers[i+1] = key;
        }
        cout << "Case " << count++ << ": " << teamMembers[(nMembers/2)] << endl;
    }
    return 0;
}