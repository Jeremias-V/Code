from sys import stdin, stdout
import math

H, D = [], []

def f(x, xf, theta):
    a = x * math.tan(theta)
    b = math.pow(x, 2) * math.sin(2*theta)
    c = 2*xf * math.pow(math.cos(theta), 2)
    return a - (b/c)

def crashes(xf, theta):
    n = len(D)
    for i in range(1, n-1):
        y = f(D[i-1], xf, theta)
        y2 = f(D[i], xf, theta)
        if(y < H[i] or y2 < H[i]):
            return True
    return False

def getAngle(xf):
    eps = 10**(-6)
    low, hi = 0, math.pi/2
    mid = (hi+low) / 2
    while(abs(hi - low) > eps):
        if(crashes(xf, mid)):
            low = mid
        else:
            hi = mid
        mid = (hi+low) / 2
    return mid

def getVel(xf, theta):
    return math.sqrt((xf * 9.8)/(math.sin(2 * theta)))

def main():
    global H, D
    line = stdin.readline().strip()
    while line != "":
        n = int(line)
        H, D = [0 for _ in range(n)], [0 for _ in range(n)]
        xf = 0
        for i in range(n):
            h, d = map(float, stdin.readline().strip().split())
            xf += d
            H[i] = h
            D[i] = xf

        ans = getAngle(xf)
        stdout.write("{:.2f} {:.2f}\n".format(math.degrees(ans), getVel(xf, ans)))
        line = stdin.readline().strip()

main()

