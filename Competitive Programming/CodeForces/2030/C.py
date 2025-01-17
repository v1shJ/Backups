def solve(n, s):
    # return a string s
    awin = False
    for i in range(n):
        if s[i] == "1":
            if (i == 0 or i == n-1) or (i > 0 and s[i-1] == "1") or (i < n-1 and s[i+1] == "1"):
                awin = True
                break 
    print("YES" if awin else "NO")

for _ in range(int(input())):
    n = int(input())
    s = input()
    solve(n, s)