from sys import stdin
from collections import deque

def finished(isEmpty):
    for b in isEmpty:
        if not b:
            return True

def main():
    a = int(input())
    while a > 0:
        stations = deque()
        N, S, Q = map(int, stdin.readline().split())
        isEmpty = [False for _ in range(N)]
        while N > 0:
            line = deque(map(int, stdin.readline().split()))
            line.popleft()
            stations.append(line)
            N -= 1
        i = 0
        current_i = (i)%(len(stations))
        carrier = deque()
        time = 0
        while stations[current_i] or carrier or finished(isEmpty):
            current_i = (i)%(len(stations))
            unload = True
            while carrier and unload:
                unload = False
                if carrier[0] == (current_i+1):
                    carrier.popleft()
                    time += 1
                    unload = True
                elif len(stations[current_i]) < Q:
                    stations[current_i].append(carrier[0])
                    carrier.popleft()
                    time += 1
                    unload = True
            while stations[current_i] and (len(carrier) < S):
                carrier.appendleft(stations[current_i][0])
                stations[current_i].popleft()
                time += 1
            if(stations[current_i]):
                isEmpty[current_i] = False
            else:
                isEmpty[current_i] = True
            if(stations[current_i] or carrier or finished(isEmpty)):
                time += 2
                i += 1
        print(time)
        a -= 1

main()
