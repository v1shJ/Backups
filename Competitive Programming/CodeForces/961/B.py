def Boquet(n, m):
    li = list(map(int, input().split()))
    li.sort(reverse=True)
    maxi = 0
    sum = 0
    for i in range(len(li)-1):
        for j in range(i+1, len(li)):
            if li[i] == li[j]-1:
                sum += li[i]
                maxi = max(maxi, sum)
    print(maxi)


f = int(input())
for what in range(f):
    n = int(input())
    m = int(input())
    Boquet(n, m)