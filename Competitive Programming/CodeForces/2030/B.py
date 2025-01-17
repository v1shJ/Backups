from itertools import combinations
def solve(n):
    if n == 1:
        print("0")
        return
    elif n == 2:
        print("01")
        return
    else:
        s = "01"
        s += "0"*(n-2)
        print(s)


for _ in range(int(input())):
    n = int(input())
    solve(n)