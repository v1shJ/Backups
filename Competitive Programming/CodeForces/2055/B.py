
for _ in range(int(input())):
    n = int(input())   
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = [i - j for i, j in zip(a, b)]
    c.sort()
    if c[1] >= -c[0]:
        print("YES")
    else:
        print("NO")
        