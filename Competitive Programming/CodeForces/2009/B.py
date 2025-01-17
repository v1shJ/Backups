def b(li):
    for i in range(len(li)-1, -1, -1):
        for c in range(i):
            if li[i][c] == "#":
                print(c, end = " ")
    print()

t = int(input())
for i in range(t):
    c = int(input())
    li = []
    for i in range(c):
        d = list(map(str, input().split()))
        li.append(d)
    b(li)