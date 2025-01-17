# cook your dish here

def yea(n):
    if(n%2 == 0):
        for i in range(1, n//2+1):
            print(i, n+1-i, end = " ")
        print()
    else:
        print(n, end = " ")
        yea(n-1)
    
t = int(input())
while(t):
    n = int(input())
    yea(n)
    t -= 1
