#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, t;
vector<vector<int>> G;
vector<int> visited, low, parent;
set<pair<int, int>> bridges;

void bridgesAux(int v){

    int i, w;
    visited[v] = low[v] = ++t;

    for(i = 0; i < G[v].size(); i++){

        w = G[v][i];

        if(visited[w] == -1){

            bridges.insert(make_pair(v, w));
            parent[w] = v;
            bridgesAux(w);
            low[v] = min(low[v], low[w]);

            // Check if it's a bridge
            if(low[w] > visited[v]){

                bridges.insert(make_pair(v, w));
                bridges.insert(make_pair(w, v));

            }
        }else if(w != parent[v]){

            if(visited[w] < visited[parent[v]]){
                /*
                If the node I'm reaching has been visited and was
                visited before the father of the current node, it
                means the connection v -> w it's a back-edge.
                */
                bridges.insert(make_pair(v, w));
            }

            low[v] = min(low[v], visited[w]);

        }
    }
}

void bridgesTarjan(){

    int i;

    for(i = 0; i < n; i++){
        if(visited[i] == -1){
            bridgesAux(i);
        }
    }
}

int main(){

    int m, i, u, v, testCase = 0;
    set<pair<int, int>>::iterator it;
    scanf("%d %d", &n, &m);

    while(n != 0 && m != 0){

        G = vector<vector<int>>(n);
        visited = vector<int>(n, -1);
        low = vector<int>(n, -1);
        parent = vector<int>(n, -1);
        bridges = set<pair<int, int>>();

        for(i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            G[--u].push_back(--v);
            G[v].push_back(u);
        }

        t = 0;
        bridgesTarjan();
        scanf("%d %d", &n, &m);
        printf("%d\n\n", ++testCase);

        for(it = bridges.begin(); it != bridges.end(); it++){
            printf("%d %d\n", it->first + 1, it->second + 1);
        }
        printf("#\n");

    }
    return 0;
}
