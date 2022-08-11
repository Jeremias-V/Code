#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Node {
	int v;
	int ftime;
	bool operator<(const Node& other) const{
		return ftime < other.ftime;
	}
};

int n, ans, time;
vector<vector<int>> G;
vector<bool> visited;
priority_queue<Node> nodeTime;

void ccDFSAux(int v){
	int i, w;
	visited[v] = true;

	for(i = 0; i < G[v].size(); i++){
		w = G[v][i];
		if(!visited[w]){
			ccDFSAux(w);
		}
	}
}

void ccDFS(){
	int i, tmpNode;

	time = 0;
	for(i = 0; i < n; i++){
		if(!visited[i]){
			ccDFSAux(i);
			nodeTime.push(Node {i, time++});
		}
	}

	fill(visited.begin(), visited.end(), false);
	
	while(!nodeTime.empty()){
		tmpNode = nodeTime.top().v;	
		if(!visited[tmpNode]){
			ccDFSAux(tmpNode);
			ans++;
		}
		nodeTime.pop();
	}
}

int main(){
	int testCases, m, i, u, v;
	scanf("%d", &testCases);
	while(testCases--){
		
		scanf("%d %d", &n, &m);
		G = vector<vector<int>>(n);
		visited = vector<bool>(n, false);
		ans = 0;

		for(i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			G[--u].push_back(--v);
		}

		ccDFS();
		printf("%d\n", ans);
	}
}
