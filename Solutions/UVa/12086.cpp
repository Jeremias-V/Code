#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int tree[2 * 200001];

void build(vector<int> &arr, int v, int l, int r){
    int m;
    if(l == r) tree[v] = arr[l];
    else{
        m = l + ((r - l) >> 1);
        build(arr, v + 1, l, m);
        build(arr, v + 2 * (m - l + 1), m + 1, r);
        tree[v] = tree[v + 1] + tree[v + 2 * (m - l + 1)];
    }
}

int sum(int v, int L, int R, int l, int r){
    int m, ans = 0;
    if(l > r) return ans;
    else if(l == L && r == R) ans = tree[v];
    else{
        m = L + ((R - L) >> 1);
        ans = sum(v + 1, L, m, l, min(r, m)) + sum(v + 2 * (m - L + 1), m + 1, R, max(l, m + 1), r);
    }
    return ans;
}

void update(int v, int L, int R, int pos, int h){
    int m;
    if(L == R) tree[v] = h;
    else{
        m = L + ((R - L) >> 1);
        if(pos <= m) update(v + 1, L, m, pos, h);
        else update(v + 2 * (m - L + 1), m + 1, R, pos, h);
        tree[v] = tree[v + 1] + tree[v + 2 * (m - L + 1)];
    }
}

int main(){

    int N, i, x, y, cases = 0;
    vector<int> potmeter;
    string line;
    char op;

    scanf("%d\n", &N);
    while(N != 0){

        potmeter = vector<int>(N);

        for(i = 0; i < N; i++){
            scanf("%d\n", &potmeter[i]);
        }
        
        build(potmeter, 0, 0, N-1);
        getline(cin, line);
        printf("Case %d:\n", ++cases);

        while(line != "END"){

            op = line[0];

            switch (op){

            case 'S':
                sscanf(line.substr(1).c_str(),"%d %d", &x, &y);
                update(0, 0, N-1, x-1, y);
                break;

            case 'M':
                sscanf(line.substr(1).c_str(),"%d %d", &x, &y);
                printf("%d\n", sum(0, 0, N-1, x-1, y-1));
                break;

            default:
                break;

            }

            getline(cin, line);
        }

        scanf("%d", &N);
        if(N != 0){
            putchar('\n');
        }
        
    }
    return 0;
}
