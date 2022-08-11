#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct AP{
    int station;
    int pigeonVal;
};

bool cmp(AP a1, AP a2){
    if(a1.pigeonVal == a2.pigeonVal){
        return a1.station < a2.station;
    }else{
        return a1.pigeonVal >= a2.pigeonVal;
    }
}

int n, m, t;
vector<vector<int>> G;
vector<int> visited, low, parents;
vector<AP> child;

void apAux(int v){
    int i, w, childs = 0;
    visited[v] = low[v] = ++t;

    for(int i = 0; i < G[v].size(); i++){
        w = G[v][i];
        if(visited[w] == -1){
            childs++;
            parents[w] = v;
            apAux(w);
            low[v] = min(low[v], low[w]);
            if(parents[v] != -1 && low[w] >= visited[v]){
                child[v].pigeonVal += 1;
            }
        }else if(w != parents[v]){
            low[v] = min(low[v], visited[w]);
        }
    }

    if(parents[v] == -1 && childs > 1){
        child[v].pigeonVal = childs;
    }

}

void ap(){
    int i;

    for(i = 0; i < n; i++){
        if(visited[i] == -1){
            apAux(i);
        }
    }
}

int main(){
    int x, y, i;
    scanf("%d %d", &n, &m);
    while(n != 0 || m != 0){
        G = vector<vector<int>>(n+1);
        visited = vector<int>(n+1, -1);
        low = vector<int>(n+1, -1);
        parents = vector<int>(n+1, -1);
        child = vector<AP>(n+1);
        for(i = 0; i < n+1; i++){
            child[i].pigeonVal = 1;
            child[i].station = i;
        }
        scanf("%d %d", &x, &y);
        while(x != -1 && y != -1){
            G[x].push_back(y);
            G[y].push_back(x);
            scanf("%d %d", &x, &y);
        }
        t = 0;
        ap();
        sort(child.begin(), child.end(), cmp);
        for(i = 0; i < m; i++){
            printf("%d %d\n", child[i].station, child[i].pigeonVal);
        }
        putchar('\n');
        scanf("%d %d", &n, &m);
    }

    return 0;
}

