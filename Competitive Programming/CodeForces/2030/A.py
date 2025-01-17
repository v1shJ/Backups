def solve(li, n):
    b = min(li)
    c = max(li)
    score = (n-1)*(c-b)
    print(score)

for _ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))
    solve(li, n)