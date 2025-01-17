def pref(li):
    prefsum = [0]
    for i in li:
        prefsum.append(i+prefsum[-1])
    return prefsum[1:]

for _ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))
    left, right = -1, n
    while left < right:
        left += 1
        right -= 1
        if li[left] == li[right]:
            continue
        elif li[left] != li[right]:
            if left > 0 and right < n-1:
                