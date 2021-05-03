#include<cstdio>
#include<queue>
#include<climits>
using namespace std;

int N;
vector<vector<pair<int, int>>> G;
vector<int> p;
vector<int> d;
vector<int> inQ;
vector<int> count;

bool bellmanFord(int s){

    int i, u, v, weight;
    queue<int> q;

    d[s] = 0;

    q.push(s);
    inQ[s] = true;

    while(!q.empty()){
        u = q.front();
        q.pop();
        inQ[u] = false;

        for(i = 0; i < G[u].size(); i++){
            v = G[u][i].first;
            weight = G[u][i].second;
            if(d[u] != INT_MAX && (d[u] + weight) < d[v]){
                d[v] = d[u] + weight;
                p[v] = u;

                if(!inQ[v]){
                    q.push(v);
                    inQ[v] = true;
                    count[v]++;

                    if(count[v] > N){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main(){
    int B, i, u, v, w;
    scanf("%d %d", &N, &B);
    while(N != 0 && B != 0){
        G = vector<vector<pair<int, int>>>(N);
        p = vector<int>(N, -1);
        d = vector<int>(N, INT_MAX);
        inQ = vector<int>(N, false);
        count = vector<int>(N, 0);
        for(i = 0; i < B; i++){
            scanf("%d %d %d", &u, &v, &w);
            G[--u].push_back(make_pair(--v, w));
            G[v].push_back(make_pair(u, -w));
        }

        if(!bellmanFord(0)){
            printf("Y\n");
        }else{
            printf("N\n");
        }

        scanf("%d %d", &N, &B);
    }
    return 0;
}
