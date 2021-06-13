#include<cstdio>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

void BFS(int v, unordered_map<int, vector<int>>& tree, unordered_map<int, bool>& visited){
    int currentV;
    vector<int> adj;
    visited[v] = true;
    queue<int> Q;
    Q.push(v);

    while(!Q.empty()){
        currentV = Q.front();
        Q.pop();
        adj = tree[currentV];
        for(int i = 0; i < adj.size(); i++){

            if(!visited[adj[i]]){
                visited[adj[i]] = true;
                Q.push(adj[i]);
            }
        }
    }
}

bool isTree(unordered_map<int, bool>& visited, unordered_map<int, int>& incidence){
    for(unordered_map<int, bool>::iterator it = visited.begin(); it != visited.end(); it++){
        if(it->second == false){
            return false;
        }
    }

    for(unordered_map<int, int>::iterator it = incidence.begin(); it != incidence.end(); it++){
        if(it->second != 1){
            return false;
        }
    }
    return true;
}

int main(){
    unsigned cases = 0;
    unordered_map<int, vector<int>> tree;
    unordered_map<int, bool> visited;
    unordered_map<int, int> incidence;
    int u, v;
    scanf("%d %d", &u, &v);
    while(u >= 0 && v >= 0){
        if(u == 0 && v == 0){
            if(tree.size() > 0){
                BFS(tree.begin()->first, tree, visited);
            }
            if((isTree(visited, incidence) && incidence.size() < tree.size()) || tree.size() == 0){
                printf("Case %d is a tree.\n", ++cases);
            }else{
                printf("Case %d is not a tree.\n", ++cases);
            }
            tree.clear();
            incidence.clear();
            visited.clear();
        }else{
            if(incidence.find(v) != incidence.end()){
                if(incidence[v] != -1){
                    incidence[v]++;
                }
            }else if(u != v){
                incidence[v] = 1;
            }else{
                incidence[v] = -1;
            }
            tree[u].push_back(v);
            tree[v].push_back(u);
            visited[u] = false;
            visited[v] = false;
        }
        scanf("%d %d", &u, &v);
    }
    return 0;
}
