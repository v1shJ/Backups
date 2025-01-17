# cook your dish here

for _ in range(int(input())):
    n = int(input())
    s = input()
    maxlen = 0

    for i in range(n):
        if s[i] == s[0]:
            maxlen = max(maxlen, i+1)
        if s[i] == s[n-1]:
            maxlen = max(maxlen, n-i)
    print(maxlen)
                