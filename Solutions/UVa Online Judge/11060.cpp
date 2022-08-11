#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int cases = 1;

void kahn(vector<vector<int>> &G, vector<int> &incidence, unordered_map<int, string> &bev){

    int i, v, u;
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > q;

    for(i = 0; i < G.size(); i++){
        if(incidence[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        v = q.top();
        q.pop();
        ans.push_back(v);

        for(i = 0; i < G[v].size(); i++){
            u = G[v][i];
            incidence[u]--;
            if(incidence[u] == 0){
                q.push(u);
            }
        }
    }

    printf("Case #%d: Dilbert should drink beverages in this order:", cases++);
    for(i = 0; i < ans.size(); i++){
        printf(" %s", bev[ans[i]].c_str());
    }
    printf(".\n\n");

}

int main(){
    int N, M, i;
    string b1, b2, beverage;
    vector<vector<int>> G;
    unordered_map<string, int> bToi;
    unordered_map<int, string> iTob;
    vector<int> incidence;
    while(scanf("%d\n", &N) != EOF){
        G = vector<vector<int>>(N);
        incidence = vector<int>(N, 0);
        bToi = unordered_map<string, int>();
        iTob = unordered_map<int, string>();
        for(i = 0; i < N; i++){
            cin >> beverage;
            bToi[beverage] = i;
            iTob[i] = beverage;
        }
        scanf("%d\n", &M);
        for(i = 0; i < M; i++){
            cin >> b1 >> b2;
            G[bToi[b1]].push_back(bToi[b2]);
            incidence[bToi[b2]]++;
        }
        kahn(G, incidence, iTob);
    }
    return 0;
}
