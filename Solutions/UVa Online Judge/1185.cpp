#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<unsigned> digits(){
    vector<unsigned> ans;
    ans.push_back(1);
    double accum = 0;
    for(int i = 1; i <= 10000000; i++){
        accum += log10(i);
        ans.push_back(accum+1);
    }
    return ans;
}

int main(){
    vector<unsigned> ans = digits();
    unsigned testCases, input;
    scanf("%u", &testCases);
    while(testCases--){
        scanf("%u", &input);
        printf("%u\n", ans[input]);
    }
    return 0;
}