#include <cstdio>
#include <vector>
using namespace std;

int ans = 0;

void DFS(int V, vector<vector<int>> &G, vector<bool> &visited){
    if(!visited[V]) ans++;
    visited[V] = true;
    vector<int> adj = G[V];
    
    for(int i = 0; i < adj.size(); i++){
        if(!visited[adj[i]]){
            DFS(adj[i], G, visited);
        }
    }

}

int main(){
    int testCases, n, m, l, i, tmp1, tmp2, tmpvec;
    vector<vector<int>> graph;
    vector<bool> visited;
    scanf("%d", &testCases);
    while(testCases--){
        scanf("%d %d %d", &n, &m, &l);
        graph = vector<vector<int>> (n);
        visited = vector<bool> (n, false);
        ans = 0;
        for(i = 0; i < m; i++){
            scanf("%d %d", &tmp1, &tmp2);
            tmp1--, tmp2--;
            graph[tmp1].push_back(tmp2);
        }
        for(i = 0; i < l; i++){
            scanf("%d", &tmp1);
            tmp1--;
            DFS(tmp1, graph, visited);
        }
        printf("%d\n", ans);
    }
    return 0;
}
