from collections import Counter
def solve(y, li):
    c = Counter(li)
    typ = c.most_common()
    typ.sort(key = lambda x: x[1], reverse=True)
    left = 0
    maxcount = 0
    total = 0
    for right in range(len(typ)):
        total += typ[right][1]
        while right - left + 1 > y or typ[right][0] > typ[left][0]+1:
            total -= typ[left][1]
            left += 1
        maxcount = max(maxcount, total)  
    print(maxcount)

t = int(input())
for _ in range(t):
    x, y = list(map(int, input().split()))
    li = list(map(int, input().split()))
    solve(y, li)