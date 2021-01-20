#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    unsigned n, accum;
    bool is;
    int elem, current;
    vector<int>::iterator it;
    vector<int> elems, subs;
    while(cin >> n){
        is = true;
        accum = 0;
        subs.clear();
        elems.clear();
        for(int i = 0; i < n; i++){
            cin >> elem;
            elems.push_back(elem);
        }
        for(int i = 1; i < n; i++){
            current = abs(elems[i-1] - elems[i]);
            accum += current;
            if(current > n-1){
                cout << "Not jolly\n";
                is = false;
                break;
            }
            it = find(subs.begin(), subs.end(), current);
            if(it != subs.end()){
                cout << "Not jolly\n";
                is = false;
                break;
            }
            subs.push_back(current);
        }
        if(is) cout << "Jolly\n";
    }
    return 0;
}