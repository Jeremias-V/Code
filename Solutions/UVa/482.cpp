#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> strToVec(string str){
    vector<string> strVec;
    string buff = "";
    for(int i = 0; i < str.size(); i++){ // -1
        if(str[i] != ' '){
            buff += str[i];
        }else{
            strVec.push_back(buff);
            buff = "";
        }
    }
    strVec.push_back(buff);
    return strVec;
} 

int main(){
    int testCases;
    string index, nums, temp;
    vector<string> indexVec, numsVec, numsCopy;
    cin >> testCases;
    getchar();
    while(testCases--){
        getchar();
        getline(cin, index);
        getline(cin, nums);
        indexVec = strToVec(index);
        numsCopy = numsVec = strToVec(nums);
        for(int i = 0; i < indexVec.size(); i++){
            numsVec[stoi(indexVec[i])-1] = numsCopy[i];
        }
        for(int i = 0; i < indexVec.size(); i++){
            cout << numsVec[i] << "\n";
        }
        if(testCases > 0)cout << endl;
    }    
    return 0;
}