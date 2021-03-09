from sys import stdin, stdout 
from collections import deque

def BFS(u):
    level = 0
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
            if(q):
                current = q.popleft()
                if(current == -1):
                    finished = True
        if(not finished):
            ans[current] = level
            for adj in G[current]:
                if(not visited[adj]):
                    q.append(adj)
                    visited[adj] = True

def main():
    global G, visited, nodeIndex, ans
    scenarios = int(stdin.readline().strip())
    for i in range(scenarios):
        P, N = map(int, stdin.readline().strip().split())
        k = 0
        G = []
        nodeIndex = {}
        ans = {}
        for j in range(P):
            tmpIn = stdin.readline()
            tmp = tmpIn.strip().split(':')
            tmp[0] = tmp[0].replace(" ", "").split(',')
            allNames = tmp[0]
            tmpNames = []
            for r in range(0, len(allNames), 2):
                if r+1 < len(allNames):
                    name = allNames[r] + ',' + allNames[r+1]
                    tmpName = name.replace(" ", "")
                    if(tmpName not in nodeIndex):
                        nodeIndex[tmpName] = k
                        k+=1
                    G.append([])
                    tmpNames.append(name)
            m = 0
            size = len(tmpNames)
            while(m < size-1):
                o = m + 1
                while(o < size):
                    current = nodeIndex[tmpNames[m]]
                    adj = nodeIndex[tmpNames[o]]
                    G[current].append(adj)
                    G[adj].append(current)
                    o += 1
                m += 1
        erdos = nodeIndex["Erdos,P."]
        stdout.write("Scenario {}\n".format(i+1))
        visited = [False] * len(G)
        BFS(erdos)
        for j in range(N):
            tmp = stdin.readline().strip()
            tmpStr = tmp
            tmp = tmp.replace(" ", "")
            if(tmp in nodeIndex):
                tmp = nodeIndex[tmp]
                if tmp in ans:
                    stdout.write("{} {}\n".format(tmpStr, ans[tmp]))
                else:
                    stdout.write("{} infinity\n".format(tmpStr))
            else:
                stdout.write("{} infinity\n".format(tmpStr))
main()
