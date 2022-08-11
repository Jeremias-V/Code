from sys import stdin, stdout

holders = []
obj, x = 0, 0

def solve(n, sum, mem):
    ans, key = None, (n, sum)
    if key in mem: ans = mem[key]
    else:
        if(sum > 5000):
            ans = (100 * obj) / sum
        elif(n == 0): ans = 0
        else:
            n -= 1
            if(n >= 0):
                if(n == x-1):
                    ans = solve(n, sum, mem)
                else:
                    ans = max(solve(n, sum, mem), solve(n, sum+holders[n], mem))
        mem[key] = ans
    return ans

def main():
    global holders, obj, x
    n, x = map(int, stdin.readline().strip().split())
    while(n != 0):
        holders = []
        for _ in range(n):
            left, right = map(int, stdin.readline().strip().split('.'))
            holders.append((left*100) + right)
        obj = holders[x-1]
        ans = solve(n, obj, dict())
        stdout.write("{:.2f}\n".format(ans))
        n, x = map(int, stdin.readline().strip().split())

main()
