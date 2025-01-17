def a(li):
    return li[1] - li[0]

t = int(input())
for i in range(t):
    li = list(map(int, input().split()))
    print(a(li))