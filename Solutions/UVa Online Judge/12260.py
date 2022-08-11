from sys import stdin, stdout, setrecursionlimit

setrecursionlimit(10**9)

vals, first = None, None

def sumT(t1, t2):
    return (t1[0]+t2[0], t1[1]+t2[1])

def cmp(t1, t2):
    ans = None
    if(t1[0] > t2[0]):
        ans = t1
    elif(t1[0] < t2[0]):
        ans = t2
    elif(t2[1] > t1[1]):
        ans = t1
    else:
        ans = t2
    return ans

def solve(i, j, mem):
    global vals, first
    ans, key = None, (i, j)
    if key in mem: ans = mem[key]
    else:
        if first == "Jan":
            c = (i // 2) if i % 2 == 0 else (i//2) + 1
        else:
            c = (i // 2)
        if i == 0 or j == 0 or c < j:
            ans = (0, 0)
        else:
            ans = cmp(sumT(solve(i-1, j-1, mem), (vals[i-1][1], vals[i-1][0])), 
                           solve(i-1, j, mem))
        mem[key] = ans
    return ans

def main():
    global vals, lim, first
    cases = int(stdin.readline().strip())
    for _ in range(cases):
        N = int(stdin.readline().strip())
        first = stdin.readline().strip()
        vals = [ tuple(map(int, stdin.readline().strip().split())) for _ in range(N) ]
        vals.sort(key=lambda x: (-x[0], x[1]))
        if first == "Jan":
            lim = (N // 2) if N % 2 == 0 else (N//2) + 1
        else:
            lim = (N // 2)
        ans = solve(N, lim, {})
        stdout.write("{} {}\n".format(sum(p for p, _ in vals)-ans[1], ans[0]))

main()
