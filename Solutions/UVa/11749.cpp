#include<cstdio>
#include<unordered_map>
#include<vector>
#include<climits>

using namespace std;
int ans, count, maxPPA;
unordered_map<int, bool> maxNodeSet;
vector<vector<pair<int, int>>> G;
vector<bool> visited;

void DFSAux(int v){
    int i;
    visited[v] = true;
    for(i = 0; i < G[v].size(); ++i){
        if(!visited[G[v][i].first] && G[v][i].second == maxPPA){
            ++count;
            DFSAux(G[v][i].first);
        }
    }
}

void DFS(){
    unordered_map<int, bool>::iterator it;
    for(it = maxNodeSet.begin(); it != maxNodeSet.end(); ++it){
        if(!visited[it->first]){
            count = 1;
            DFSAux(it->first);
            ans = max(ans, count);
        }
    }
}


int main(){
    int n, m, i, u, v, ppa;
    scanf("%d %d", &n, &m);
    while(n != 0 && m != 0){
        maxPPA = INT_MIN;
        maxNodeSet = unordered_map<int, bool>();
        G = vector<vector<pair<int, int>>>(n);
        visited = vector<bool>(n, false);
        for(i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &ppa);
            --u;
            --v;
            if(ppa > maxPPA){
                maxPPA = ppa;
                maxNodeSet = unordered_map<int, bool>();
                maxNodeSet[u] = true;
                G[u].push_back(make_pair(v, ppa));
                G[v].push_back(make_pair(u, ppa));
            }else if(ppa == maxPPA){
                maxNodeSet[u] = true;
                G[u].push_back(make_pair(v, ppa));
                G[v].push_back(make_pair(u, ppa));
            }
        }
        ans = 0;
        DFS();
        printf("%d\n", ans);
        scanf("%d %d", &n, &m);
    }
    return 0;
}
