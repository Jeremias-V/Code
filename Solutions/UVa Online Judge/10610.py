from sys import stdin, stdout 
from collections import deque
import math

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
            for adj in G[current]:
                if(adj == 1):
                    stdout.write("Yes, visiting {} other holes.\n".format(level))
                    return
                if(not visited[adj]):
                    q.append(adj)
                    visited[adj] = True
    stdout.write("No.\n")

def distance(ip, fp):
    return math.sqrt(math.pow(fp[0] - ip[0], 2) + math.pow(fp[1] - ip[1], 2))

def main():
    global G, visited
    v, m = map(int, stdin.readline().split())
    while (v != 0 and m !=0 ):
        s = m * 60
        maxDist = v * s
        points = []
        G = []
        visited = []
        (x0, y0) = map(float, stdin.readline().split())
        ip = (x0, y0)
        points.append(ip)
        G.append([])
        visited.append(False)
        xf, yf = map(float, stdin.readline().split())
        fp = (xf, yf)
        points.append(fp)
        G.append([])
        visited.append(False)
        if(distance(ip, fp) <= maxDist):
            G[0].append(1)
            G[1].append(0)
        tmp = stdin.readline()
        while(tmp != "\n"):
            x, y = map(float, tmp.split())
            points.append((x,y))
            G.append([])
            visited.append(False)
            i = 0
            size = (len(points) - 1)
            while(i < size):
                p1 = points[i]
                p2 = points[-1]
                dist = distance(p1, p2)
                if(dist <= maxDist):
                    G[i].append(size)
                    G[size].append(i)
                i += 1
            tmp = stdin.readline()
        BFS(0)
        v, m = map(int, stdin.readline().split())
main()
