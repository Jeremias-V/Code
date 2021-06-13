#include<cstdio>
#include<vector>
#include<climits>
#include<set>
#include<algorithm>
using namespace std;

int diam, maxNode;
bool secondDFS;
vector<int> order, pred;

void getPath(vector<int>& pred, int i){
    if(pred[i] != -1){
        order.push_back(pred[i] + 1);
        getPath(pred, pred[i]);
    }
}

void DFS(int v, vector<vector<int>>& G, vector<bool>& visited, vector<int>& dist, int currDist){
    int i, w;
    visited[v] = true;
    currDist++;
    for(i = 0; i < G[v].size(); i++){
        w = G[v][i];
        if(!visited[w]){
            if(secondDFS) pred[w] = v;
            dist[w] = currDist;
            DFS(w, G, visited, dist, currDist);
            if(dist[w] > diam){
                diam = dist[w];
                maxNode = w;
            }
        }
    }
}

void getWorst(vector<int>& dist, set<int>& ans, int maxDist){
    for(int i = 0; i < dist.size(); i++){
        if(dist[i] == maxDist){
            ans.insert(i+1);
        }
    }
}

void printWorst(set<int>&worst){
    printf("Worst Roots :");
    for(set<int>::iterator it = worst.begin(); it != worst.end(); it++){
        printf(" %d", *it);
    }
    putchar('\n');
}

int main(){

    int n, nodes, i, j, u, tmp1, tmp2;
    vector<vector<int>> G;
    vector<bool> visited;
    vector<int> dist;
    set<int> worst;

    while(scanf("%d", &n) != -1){

        G = vector<vector<int>>(n);

        for(i = 0; i < n; i++){
            scanf("%d", &nodes);
            for(j = 0; j < nodes; j++){
                scanf("%d", &u);
                G[i].push_back(u-1);
            }
        }

        diam = INT_MIN;
        visited = vector<bool>(n, false);
        dist = vector<int>(n, 0);
        secondDFS = false;
        DFS(0, G, visited, dist, 0);

        diam = INT_MIN;
        visited = vector<bool>(n, false);
        dist = vector<int>(n, 0);
        order = vector<int>();
        pred = vector<int>(n, -1);
        secondDFS = true;
        DFS(maxNode, G, visited, dist, 0);
        secondDFS = false;
        getPath(pred, maxNode);
        reverse(order.begin(), order.end());
        order.push_back(maxNode+1);
        tmp1 = order[diam/2];

        if(diam & 1){

            tmp2 = order[(diam+1)/2];
            if(tmp1 > tmp2){
                printf("Best Roots  : %d %d\n", tmp2, tmp1);
            }else{
                printf("Best Roots  : %d %d\n", tmp1, tmp2);
            }

            // Check first center
            diam = INT_MIN;
            visited = vector<bool>(n, false);
            dist = vector<int>(n, 0);
            DFS(tmp1-1, G, visited, dist, 0);
            worst.clear();
            getWorst(dist, worst, diam);

            // Check second center 
            diam = INT_MIN;
            visited = vector<bool>(n, false);
            dist = vector<int>(n, 0);
            DFS(tmp2-1, G, visited, dist, 0);
            getWorst(dist, worst, diam);
            printWorst(worst);

        }else{

            printf("Best Roots  : %d\n", tmp1);
            diam = INT_MIN;
            visited = vector<bool>(n, false);
            dist = vector<int>(n, 0);
            DFS(tmp1-1, G, visited, dist, 0);
            worst.clear();
            getWorst(dist, worst, diam);
            printWorst(worst);

        }
    }

    return 0;
}
