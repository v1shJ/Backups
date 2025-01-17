# cook your dish here

for _ in range(int(input())):
    n = int(input())
    f, g = 0, 0
    for i in range(1, n+1):
        if n%i == 0:
            if i%2 == 0:
                f += 1
            else:
                g += 1
    if f == g:
        print(0)
    elif g > f:
        print(-1)
    else:
        print(1)