from sys import stdin, stdout

def DFSAux(v):
    global count
    visited[v] = True
    for adj in G[v]:
        if(not visited[adj[0]] and adj[1] == maxPPA):
            count += 1
            DFSAux(adj[0])

def DFS():
    global ans, count
    for node in maxNodeSet:
        if(not visited[node]):
            count = 1
            DFSAux(node)
            ans = max(ans, count)

def main():
    global G, visited, maxPPA, maxNodeSet, ans, count
    n, m = map(int, stdin.readline().strip().split())
    while(n != 0 and m != 0):
        maxPPA = -2147483648
        maxNodeSet = dict()
        G = [[] for _ in range(n)]
        visited = [False]*n
        for _ in range(m):
            u, v, ppa = map(int, stdin.readline().strip().split())
            u -= 1
            v -= 1
            if ppa > maxPPA:
                maxPPA = ppa
                maxNodeSet = dict()
                maxNodeSet[u] = None
                G[u].append((v, ppa))
                G[v].append((u, ppa))
            elif ppa == maxPPA:
                G[u].append((v, ppa))
                G[v].append((u, ppa))
                maxNodeSet[u] = None
        ans = 0
        DFS()
        stdout.write(str(ans) + '\n')
        n, m = map(int, stdin.readline().strip().split())

main()
