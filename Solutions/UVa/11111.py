from sys import stdin
from collections import deque

def main():
    read = stdin.readlines()
    for l in read:
        current = l.split()
        current = list(map(int, current))
        stack = deque()
        level = deque()
        if current:
            stack.appendleft(current[0])
            level.appendleft(current[0])
            fail = False
            i = 1
            while i < len(current) and not fail:
                if(stack):
                    if(current[i] < 0):
                        stack.appendleft(current[i])
                        level[0] -= current[i]
                        if(level[0] >= 0):
                            fail = True
                        else:
                            level.appendleft(current[i])
                    if(((current[i] + stack[0]) == 0) and not fail):
                        stack.popleft()
                        level.popleft()
                i+=1
        if(stack):
            print(":-( Try again.")
        else:
            print(":-) Matrioshka!")
            
main()
