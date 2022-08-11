"""
OnlineJudge 10069
"""
from sys import stdin, stdout, setrecursionlimit

setrecursionlimit(1<<24)
T, P = None, None

def ds(n, m, memo):
    ans, key = None, (n, m)
    if key in memo: ans = memo[key]
    else:
        if m == 0: ans = 1
        elif m > n: ans = 0
        else:
            ans = ds(n-1, m, memo)
            if T[n-1] == P[m-1]:
                ans += ds(n-1, m-1, memo)
        memo[key] = ans
    return ans

def main():
    global T, P
    N = int(stdin.readline().strip())
    for _ in range(N):
        T = stdin.readline().strip()
        P = stdin.readline().strip()
        stdout.write(str(ds(len(T), len(P), dict())) + '\n')

main()

