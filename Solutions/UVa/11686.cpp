#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void kahn(vector<vector<int>> &G, vector<int> &incidence){

    int i, v, u, count = 0;
    vector<int> ans;
    queue<int> q;

    for(i = 0; i < G.size(); i++){
        if(incidence[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        v = q.front();
        q.pop();
        ans.push_back(v+1);

        for(i = 0; i < G[v].size(); i++){
            u = G[v][i];
            incidence[u]--;
            if(incidence[u] == 0){
                q.push(u);
            }
        }
        count++;
    }

    if(count != G.size()){
        printf("IMPOSSIBLE\n");
    }else{
        for(i = 0; i < ans.size(); i++){
            printf("%d\n", ans[i]);
        }
    }

}

int main(){

    int n, m, u, v, i;
    vector<vector<int>> G;
    vector<int> incidence, ans;
    scanf("%d %d\n", &n, &m);

    while(n != 0){

        G = vector<vector<int>>(n);
        incidence = vector<int>(n, 0);
        for(i = 0; i < m; i++){
            scanf("%d %d\n", &u, &v);
            u--, v--;
            G[u].push_back(v);
            incidence[v]++;
        }
        kahn(G, incidence);
        scanf("%d %d\n", &n, &m);

    }
    return 0;
}
