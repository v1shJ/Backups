t = int(input())
li1 = list(map(int, input().split()))
li2 = list(map(int, input().split()))
MOD = 10**9 + 7
for i in range(t):
    print(pow(2, li2[i], MOD))