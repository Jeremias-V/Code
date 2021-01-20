from collections import deque

def DFS(currentNode):
    visited[currentNode] = True
    print(currentNode)
    adjacent = graph[currentNode]
    for next in adjacent:
        if(not visited[next]):
            DFS(next)

def BFS(start):
    q = deque()
    q.append(start)
    visited[start] = True
    while(q):
        current = q[0]
        q.popleft()
        print(current)
        for adj in graph[current]:
            if(not visited[adj]):
                q.append(adj)
                visited[adj] = True

def main():
    global graph, visited
    graph = []
    graph.append([4,5,1])
    graph.append([0,2,3,4])
    graph.append([1,5])
    graph.append([1])
    graph.append([0,1])
    graph.append([0,2])
    graph.append([])
    visited = [False for _ in graph]
    print(graph)
    print(visited)
    print("DFS")
    DFS(0)
    visited = [False for _ in graph]
    print("BFS")
    BFS(0)
main()