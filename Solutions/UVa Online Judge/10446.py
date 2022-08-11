from sys import stdin, stdout

mem = {}

def trib(n, back):
    global mem
    sum, key = 0, (n, back)
    if key in mem:
        sum = mem[key]
    else:
        if n <= 1: return 1
        else: sum += 1
        for i in range(1, back+1):
            sum += trib(n-i, back)
        mem[key] = sum
    return sum

def main():
    global count
    n, back = map(int, stdin.readline().strip().split())
    case = 0
    while(n <= 60):
        case += 1
        ans = trib(n, back)
        stdout.write("Case {}: {}\n".format(case, ans))
        n, back = map(int, stdin.readline().strip().split())

main()

