from sys import stdin, stdout

charsPos, idx, left, right = dict(), -1, -1, -1

def binSearch(c):
    global idx, left, right
    A = charsPos[c]
    low, hi = 0, len(A)
    while (low < hi):
        mid = low + ((hi - low) >> 1)
        if(A[mid] <= idx):
            low = mid+1
        else:
            hi = mid
    if (low < len(A) and A[low] >= idx):
        if(left == -1):
            left = A[0]
        right = idx = A[low]

def main():
    global charsPos, idx, left, right
    S = stdin.readline().strip()
    for i in range(len(S)):
        c = S[i]
        if c in charsPos:
            charsPos[c].append(i)
        else:
            charsPos[c] = [i]
    Q = int(stdin.readline().strip())
    for _ in range(Q):
        idx, left, right = -1, -1, -1
        X = stdin.readline().strip()
        found = True
        i = 0
        while (i < len(X)):
            c = X[i]
            if(c in charsPos):
                prev = idx
                binSearch(c)
                i += 1
                if (prev == idx):
                    i = len(X)
                    found = False
            else:
                i = len(X)
                found = False
        if(found):
            stdout.write("Matched {} {}\n".format(left, right))
        else:
            stdout.write("Not matched\n")

main()
