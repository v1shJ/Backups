def B(li):
    if len(li)%2 == 0:
        fleg = False
    else:
        fleg = True
    count = 1
    for i in range(len(li)):
        if i+1 != len(li) and count == 1:
            li[i+1] = max(li[i], li[i+1])
            count=0
        elif i+1 != len(li) and count == 0:
            li[i+1] = min(li[i], li[i+1])
            count = 1
        else:
            print(li)
            return min(li) if count else max(li)

t = int(input())
for i in range(t):
    a = int(input())
    li = list(map(int, input().split()))
    print(B(li))