from sys import stdin, stdout

def tarjanAux(v):
    global t
    childs = 0
    t += 1
    visited[v] = low[v] = t

    for i in range(len(G[v])):
        w = G[v][i]

        if(visited[w] == -1):

            childs += 1
            parents[w] = v
            tarjanAux(w)
            low[v] = low[v] if (low[v] < low[w]) else low[w]

            # Verify if its an articulation point
            if(parents[v] != -1 and low[w] >= visited[v]):
                apNodes.add(v)

        elif(w != parents[v]):
            low[v] = low[v] if (low[v] < visited[w]) else visited[w]

    if(parents[v] == -1 and childs > 1):
        apNodes.add(v)

def tarjan():
    for i in range(N):
        if(visited[i] == -1):
            tarjanAux(i)

def main():
    global N, G, visited, t, low, parents, apNodes
    count = 0
    N = int(stdin.readline().strip())
    while(N):

        t = 0
        G = [[] for _ in range(N)]
        visited = [-1]*N
        low = [-1]*N
        parents = [-1]*N
        apNodes = set()
        strToNode = dict()
        nodeToStr = dict()

        for i in range(N):
            place = stdin.readline().strip()
            strToNode[place] = i
            nodeToStr[i] = place

        R = int(stdin.readline().strip())

        for _ in range(R):
            u, v = stdin.readline().strip().split()
            u, v = strToNode[u], strToNode[v]
            G[u].append(v)
            G[v].append(u)

        tarjan()

        count += 1
        stdout.write("City map #{}: {} camera(s) found\n".format(count, len(apNodes)))
        if(apNodes):
            apNodes = [nodeToStr[v] for v in apNodes]
            apNodes.sort()
            for ap in apNodes:
                stdout.write(ap + '\n')

        N = int(stdin.readline().strip())
        if(N != 0):
            stdout.write('\n')

main()

