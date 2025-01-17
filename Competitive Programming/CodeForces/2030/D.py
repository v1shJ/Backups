def solve(p, s, t):
    s = list(s)
    if s[t] == "L": s[t] = "R"
    else: s[t] = "L"
    # sort p in increasing order wtfff
    

for _ in range(int(input())):
    n, q = list(map(int, input().split()))
    p = list(map(int, input().split()))
    s = input()
    for _ in range(q):
        solve(p, s, int(input()))