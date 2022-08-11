from sys import stdin, stdout

def getAns():
    ans = []
    for n in ansArr:
        if(n != 0):
            ans.append(n)
    return map(str, ans)

def preOrder(treePos):
    global inputList, ansArr, i
    if(i < len(inputList)):
        if(inputList[i] != -1):
            ansArr[treePos] += inputList[i]
            i += 1
            preOrder(treePos-1)
            preOrder(treePos+1)
        else:
            i += 1

def main():
    global inputList, ansArr, i
    ansArr = [0] * 81
    inputList = list(map(int, stdin.readline().strip().split()))
    case = 1
    while(inputList[0] != -1):
        i = 0
        preOrder(40)
        stdout.write("Case {}:\n{}\n\n".format(case, ' '.join(getAns())))
        case += 1
        ansArr = [0] * 81
        inputList = list(map(int, stdin.readline().strip().split()))

main()
