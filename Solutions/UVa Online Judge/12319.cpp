#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int n;
string input;
vector<vector<int>> G1, G2;

vector<vector<int>> floydWarshall(vector<vector<int>>& G){
    int i, j, k;
    vector<vector<int>> d = vector<vector<int>>(n, vector<int>(n, INT_MAX));

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            d[i][j] = G[i][j];
        }
    }
    for(i = 0; i < n; i++){
        d[i][i] = 0;
    }

    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if((d[i][k] != INT_MAX && d[k][j] != INT_MAX) && ((d[i][k] + d[k][j]) < d[i][j])){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    return d;
}

void readInput(vector<vector<int>>& G){
    int j, tmpNum, first, tmpJ;
    string tmp = "";
    for(j = 0; j < input.size(); j++){
        if(tmp != "" && (input[j] == ' ' || input[j] == '\n')){
            first = stoi(tmp) - 1;
            tmp = "";
            tmpJ = j;
            j = input.size();
        }else if(input[j] >= '0' && input[j] <= '9'){
            tmp += input[j];
        }
    }

    for(j = tmpJ; j < input.size()+1; j++){
        if(j == input.size() && tmp != ""){
            tmpNum = stoi(tmp) - 1;
            G[first][tmpNum] = 1;
        }else if(tmp != "" && (input[j] == ' ' || input[j] == '\n')){
            tmpNum = stoi(tmp) - 1;
            G[first][tmpNum] = 1;
            tmp = "";
        }else if(input[j] >= '0' && input[j] <= '9'){
            tmp += input[j];
        }
    }
}

int main(){
    int i, j, A, B, newDist;
    bool ans;
    vector<vector<int>> d1, d2;
    scanf("%d\n", &n);
    while(n != 0){
        G1 = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        for(i = 0; i < n; i++){
            getline(cin, input);
            readInput(G1);
        }
        G2 = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        for(i = 0; i < n; i++){
            getline(cin, input);
            readInput(G2);
        }
        
        scanf("%d %d\n", &A, &B);
        d1 = floydWarshall(G1);
        d2 = floydWarshall(G2);
        

        newDist = (A * d1[0][0]) + B;
        i = 0;
        ans = false;
        while(i < n && !ans){
            j = 0;
            while(j < n && !ans){
                newDist = (A * d1[i][j]) + B;
                if(d2[i][j] > newDist){
                    ans = true;
                }
                j++;
            }
            i++;
        }

        if(ans){
            printf("No\n");
        }else{
            printf("Yes\n");
        }

        scanf("%d\n", &n);
    }
    return 0;
}
