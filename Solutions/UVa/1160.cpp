#include <climits>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int padre[100000+1], rango[100000+1];

void makeSet(int v){
    padre[v] = v;
    rango[v] = 0;
}

int findSet(int v){
    if(v == padre[v]){
        return v;
    }else{
        padre[v] = findSet(padre[v]);
        return padre[v];
    }
}

void unionSet(int u, int v){
    u = findSet(u);
    v = findSet(v);

    if(u != v){
        if(rango[u] < rango[v]){
            swap(u, v);
        }

        padre[v] = u;
        if(rango[u] == rango[v]){
            rango[u]++;
        }
    }
}

struct Arista{
    int u, v, peso;

    Arista(){}

    Arista(int x, int y, int p){
        u = x;
        v = y;
        peso = p;
    }
};

bool operator<(Arista a, Arista b){
        return b.peso <= a.peso;
}

int n, ans;
vector<Arista> aristas;

void kruskal(){
    int u, v;

    sort(aristas.begin(), aristas.end());

    for(vector<Arista>::iterator it = aristas.begin(); it != aristas.end(); ++it){
        u = it->u;
        v = it->v;

        if(findSet(u) != findSet(v)){
            unionSet(u, v);
        }else{
            ans++;
        }
    }
}

int main(){
    int u, v, m = 0, max = INT_MIN;
    while(scanf("%d", &u) != EOF){

        if(u != -1){

            scanf("%d", &v);
            max = (u > max) ? u : max;
            max = (v > max) ? v : max;
            makeSet(u);
            makeSet(v);
            aristas.push_back(Arista(u, v, u+v));
            m++;

        }else{

            ans = 0;
            n = max;
            kruskal();
            printf("%d\n", ans);
            aristas = vector<Arista>();
            m = 0;
            max = INT_MIN;

        }
    }
    return 0;
}
