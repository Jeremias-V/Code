from sys import stdin

chars = None

def solve(perm, i):
    if i == len(chars):
        print(''.join(perm))
    else:
        if i == 0:
            perm.append(chars[i])
            solve(perm, i+1)
        else:
            j = 0
            while j < len(chars) and j <= len(perm):
                perm.insert(j, chars[i])
                solve(perm, i+1)
                del perm[j]
                j += 1

def main():

    global chars

    lines = stdin.readlines()
    for i in range(len(lines)):
        chars = lines[i].strip()
        solve([], 0)
        if i+1 < len(lines):
            print()

main()
