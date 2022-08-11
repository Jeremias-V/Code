#include<iostream>
#include<map>
using namespace std;

int main(){
    int n, m, common, temp;
    map<int, bool> cds;
    cin >> n >> m;
    while(n != 0 && m != 0){
        common = 0;
        while(n--){
            cin >> temp;
            cds.insert(make_pair(temp, true));
        }
        while(m--){
            cin >> temp;
            if(cds[temp]){
                common++;
            }
        }
        cout << common << endl;
        cin >> n >> m;
        cds.clear();
    }
    return 0;
}