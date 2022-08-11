"""
UVa 787 Solution
Jeremias Villalobos Tenorio
Used and adapted code provided by Camilo Rocha
"""

from sys import stdin, stdout

seq = []

def msp(low, hi):
    ans = None
    if (low == hi):
        ans = -999999
    elif (low+1 == hi):
        ans = max(-999999, seq[low])
    else:
        mid = low + ((hi-low) >> 1)
        ans = max(msp(low, mid), msp(mid, hi))
        ans = max(ans, best_crossing(low, mid, hi))
    return ans

def best_crossing(low, mid, hi):
    bl, pl, l = seq[mid-1], seq[mid-1], mid-2
    wl = bl
    while (l >= low):
        pl *= seq[l]
        bl = max(bl, pl)
        wl = min(wl, pl)
        l -= 1
    br, pr, r = seq[mid], seq[mid], mid+1
    wr = br
    while (r<hi):
        pr *= seq[r]
        br = max(br, pr)
        wr = min(wr, pr)
        r += 1
    if(wl*wr > bl*br):
        return wl*wr
    else:
        return bl*br

def main():
    global seq
    lines = stdin.readlines()
    for line in lines:
        currSeq = list(map(int, line.strip().split()))
        if(currSeq[-1] == -999999):
            if(len(currSeq) > 1):
                currSeq.pop()
                seq.extend(currSeq)
            stdout.write(str(msp(0, len(seq)))+ '\n')
            seq = []
        else:
            seq.extend(currSeq)

main()
