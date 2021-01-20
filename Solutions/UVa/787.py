from sys import stdin

def main():
    read = stdin.readlines()
    for l in read:
        current = l.split()
        current.pop()
        current = list(map(int, current))
        maxNum = -999999
        size = len(current)
        i = 0
        while(i < size):
            accum = 1
            j = i
            while(j < size):
                accum *= current[j]
                if(accum > maxNum):
                    maxNum = accum
                j += 1
            i += 1
        print(maxNum)

        
main()