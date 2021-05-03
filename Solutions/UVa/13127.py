from sys import stdin, stdout
from heapq import heappop, heappush

def dijkstra():
    global G, d, p, police

    d = [float("inf") for i in range(len(G))]
    p = [-1 for i in range(len(G))]
    
    heap = []
    for pol in police:
        d[pol] = 0
        heappush(heap, (0, pol))

    while len(heap) != 0:
        costo, u = heappop(heap)

        if costo == d[u]:
            for v, w in G[u]:
                if d[v] > d[u] + w:
                    d[v] = d[u] + w
                    p[v] = u
                    heappush(heap, (d[v], v))

def main():
    global G, d, p, police

    line = stdin.readline().strip()

    while(line != ""):

        line = line.split()
        N, M, B, P = map(int, line)
        G = [[] for _ in range(N)]

        for _ in range(M):
            u, v, t = map(int, stdin.readline().strip().split())
            G[u].append((v, t))
            G[v].append((u, t))

        if(B != 0):
            banks = set(map(int, stdin.readline().strip().split()))
        else:
            banks = []

        if(P != 0):
            police = set(map(int, stdin.readline().strip().split()))
        else:
            police = []

        dijkstra()
        
        S = 0
        E = -1
        
        if(len(banks) > 0):
            banks = sorted(banks)

        for b in banks:
            if(d[b] > E):
                E = d[b]

        ansList = []
        
        for i in banks:
            if(d[i] == E):
                S += 1
                ansList.append(str(i))

        if(E == float("inf")):
            E = '*'

        stdout.write("{} {}\n{}\n".format(S, E, " ".join(ansList)))
        line = stdin.readline().strip()

main()
