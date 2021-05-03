import math

def catalan(n):
    a = math.factorial(2*n)
    b = (math.factorial(n+1)*math.factorial(n))
    return a//b

def main():
    n = int(input())
    while(n != 0):
        print(math.factorial(n)*catalan(n))
        n = int(input())

main()
