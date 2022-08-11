import math
from sys import stdin

def stabs(A):
    N = len(A)
    A.sort()
    ans = 0
    lim = 0
    i = 0
    while i < N:
        ans += 1
        lim = A[i][1]
        i += 1
        while i < N and A[i][0] <= lim:
            if A[i][1] < lim: 
                lim = A[i][1]
            i += 1
            
    return ans

def main():
    n, d = map(int, stdin.readline().strip().split())
    case = 1
    while n != 0:
        A = []
        works = True
        for _ in range(n):
            x, y = map(int, stdin.readline().strip().split())
            xi, yi = x, y
            a = 1
            b = -2 * xi
            c = xi**2 + yi**2 - d**2
            if (4*a*c > (b**2)):
                works = False
            l, r = 0, 0
            if(works):
                l = ((-b) - (math.sqrt((b**2) - (4*a*c)))) / 2*a 
                r = ((-b) + (math.sqrt((b**2) - (4*a*c)))) / 2*a 
            I = (l, r)
            A.append(I)
        if(works):
            print("Case {}: {}".format(case, stabs(A)))
        else:
            print("Case {}: {}".format(case, -1))
        case += 1
        stdin.readline()
        n, d = map(int, stdin.readline().strip().split())



main()