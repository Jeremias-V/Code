from sys import stdin, stdout
from collections import deque


def bellmanFord(s):
    global d, p, G
    n, ans = len(G), True
    d = [[float('inf') for _ in range(n)] for _ in range(n)]
    p = [-1 for _ in range(n)]
    
    d[0][s] = 0
    for i in range(1, N):
        for v in range(n):
            d[i][v] = min(d[i][v], d[i - 1][v])
            for u in G[v]:
                if d[i][u] > d[i-1][v] + w[v][u]:
                    d[i][u] = d[i-1][v] + w[v][u]
                    p[u] = v

    return ans


def main():
    global G, d, p, w, N
    scenarios = int(stdin.readline().strip())

    for i in range(scenarios):

        stdin.readline()
        N = int(stdin.readline().strip())
        cityToInt = {}
        ansQ = {}
        k = 0
        G = [[] for _ in range(N)]
        w = [[float('inf') for _ in range(N)] for _ in range(N)]

        for _ in range(N):
            city = stdin.readline().strip()
            cityToInt[city] = k
            k += 1

        M = int(stdin.readline().strip())

        for _ in range(M):
            c1, c2, weight = stdin.readline().strip().split()
            weight = int(weight)
            G[cityToInt[c1]].append(cityToInt[c2])
            if(weight < w[cityToInt[c1]][cityToInt[c2]]):
                w[cityToInt[c1]][cityToInt[c2]] = weight

        queries = deque(map(int, stdin.readline().strip().split()))
        queries.popleft()
        stdout.write("Scenario #{}\n".format(i+1))

        bellmanFord(0)
        
        for q in queries:
            if(q >= N-1):
                ans = d[N-1][-1]
            else:
                ans = d[q+1][-1]
            
            if(ans != float('inf')):
                stdout.write("Total cost of flight(s) is ${}\n".format(ans))
            else:
                stdout.write("No satisfactory flights\n")

        if(i < scenarios-1):
            stdout.write('\n')

main()
