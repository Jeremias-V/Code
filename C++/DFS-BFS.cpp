/* 
G = Graph, V = Vertices/Nodes, E = Edges/Links
G = (V, E)
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void DFS(int V, vector<vector<int>> &G, vector<bool> &visited){

    visited[V] = true;
    cout << V << endl;

    vector<int> adj = G[V];

    for(int i = 0; i < adj.size(); i++){
        if(!visited[adj[i]])
            DFS(adj[i], G, visited);
    }

}

void BFS(int V, vector<vector<int>> &G, vector<bool> &visited){

    int currentV;
    vector<int> adj;

    visited[V] = true;

    queue<int> Q;
    Q.push(V);

    while(!Q.empty()){

        currentV = Q.front();
        cout << currentV << endl;
        Q.pop();
        adj = G[currentV];

        for(int i = 0; i < adj.size(); i++){

            if(!visited[adj[i]]){
                visited[adj[i]] = true;
                Q.push(adj[i]);
            }

        }

    }

}


int main(){

    vector<vector<int>> G(7);

    G[0].push_back(4);
    G[0].push_back(5);
    G[0].push_back(1);
    
    G[1].push_back(0);
    G[1].push_back(2);
    G[1].push_back(3);
    G[1].push_back(4);
    
    G[2].push_back(1);
    G[2].push_back(5);
    
    G[3].push_back(1);
    
    G[4].push_back(0);
    G[4].push_back(1);
    
    G[5].push_back(0);
    G[5].push_back(2);
    
    vector<bool> visited(7, false);

    cout << "DFS" << endl;
    DFS(0, G, visited);

    visited = vector<bool>(7, false);

    cout << "BFS" << endl;
    BFS(0, G, visited);

    return 0;
}