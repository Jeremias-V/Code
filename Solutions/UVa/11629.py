from sys import stdin
from collections import deque

def main():
    read = stdin.readline().split()
    P = int(read[0])
    G = int(read[1])
    output = ""
    case = 1
    parties = dict()
    while(P > 0):
        read = stdin.readline().split()
        parties[read[0]] = list(map(int,(read[1].split('.'))))
        P -= 1
    while(G > 0):
        read = deque(stdin.readline().split())
        num = int(read[-1])
        read.pop()
        comparator = read[-1]
        read.pop()
        acum = 0
        decim = 0
        for word in read:
            if word != '+':
                acum += parties[word][0]
                decim += parties[word][1]
                if(decim > 9):
                    acum += 1
                    decim -= 10
        if(comparator == ">"):
            if(acum > num):
                output += "Guess #{} was correct.\n".format(case)
            elif(acum == num and decim > 0):
                output += "Guess #{} was correct.\n".format(case)
            else:
                output += "Guess #{} was incorrect.\n".format(case)
        elif(comparator == "<"):
            if(acum < num):
                output += "Guess #{} was correct.\n".format(case)
            else:
                output += "Guess #{} was incorrect.\n".format(case)
        elif(comparator == ">="):
            if(acum >= num):
                output += "Guess #{} was correct.\n".format(case)
            else:
                output += "Guess #{} was incorrect.\n".format(case)
        elif(comparator == "<="):
            if(acum < num):
                output += "Guess #{} was correct.\n".format(case)
            elif(acum == num and decim == 0):
                output += "Guess #{} was correct.\n".format(case)
            else:
                output += "Guess #{} was incorrect.\n".format(case)
        elif(comparator == "="):
            if(acum == num and decim == 0): 
                output += "Guess #{} was correct.\n".format(case)
            else:
                output += "Guess #{} was incorrect.\n".format(case)
        case += 1
        G -= 1
    print(output, end="")
main()
