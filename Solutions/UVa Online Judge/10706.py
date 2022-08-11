import math
from sys import stdin, stdout 

def generateArr(A):
    i = 1
    while(len(A) < 145229):
        if i >= 10:
            tmp = str(i)
            for c in tmp:
                if(len(A) < 145229):
                    A.append(c)
        else:
            A.append(str(i))
        i += 1

def generateSearchArr(A):
    A.append(0)
    digits = 0
    for i in range(1, 31268):
        digits += math.floor(math.log10(i))
        A.append(i + A[i-1] + digits)

def binarySearch(A, i):
    low, hi = 0, len(A)
    while low + 1 !=  hi:
        mid = low + ((hi - low) >> 1)
        if A[mid] < i:
            low = mid
        else:
            hi = mid
    ans = low+1
    return ans

def main():
    a = int(stdin.readline().strip())
    S = []
    ansArr = []
    generateSearchArr(S)
    generateArr(ansArr)
    ans = ""
    while a > 0:
        i = int(stdin.readline().strip())
        k = binarySearch(S, i)
        before = S[k-1]
        pos = i - before - 1
        ans += str(ansArr[pos]) + '\n'
        a -= 1
    stdout.write(ans)
main()
