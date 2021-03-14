from sys import stdin, stdout
from collections import deque

def BFS(u, end):
    if(u == end):
        return 0
    level = 1
    q = deque()
    q.append(u)
    q.append(-1)
    visited[u] = True
    finished = False
    while(q):
        current = q.popleft()
        if(current == -1):
            level += 1
            q.append(-1)
            current = q.popleft()
            if(current == -1):
                finished = True
        if(not finished):
            for adj in G[current]:
                if(adj == end):
                    return level
                if(not visited[adj]):
                    q.append(adj)
                    visited[adj] = True
    return -1

def main():
    global G, visited
    dataSets = int(stdin.readline().strip())
    stdout.write("SHIPPING ROUTES OUTPUT\n\n")
    for i in range(1, dataSets+1):
        M, N, P = map(int, stdin.readline().strip().split())
        G = [[] for _ in range(M)]
        nodeToIndex = dict()
        nodes = list(stdin.readline().strip().split())
        k = 0
        for n in nodes:
            nodeToIndex[n] = k
            k += 1
        for _ in range(N):
            u, v = stdin.readline().strip().split()
            u = nodeToIndex[u]
            v = nodeToIndex[v]
            G[u].append(v)
            G[v].append(u)
        stdout.write("DATA SET  {}\n\n".format(i))
        for _ in range(P):
            size, origin, destination = stdin.readline().strip().split()
            visited = [False]*M
            size = int(size)
            origin = nodeToIndex[origin]
            destination = nodeToIndex[destination]
            ans = BFS(origin, destination)
            if(ans != -1):
                ans = ans * size * 100
                stdout.write("${}\n".format(ans))
            else:
                stdout.write("NO SHIPMENT POSSIBLE\n")
        stdout.write('\n')
    stdout.write("END OF OUTPUT\n")
main()
