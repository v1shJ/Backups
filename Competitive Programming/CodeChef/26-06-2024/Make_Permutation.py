# cook your dish here
def is_perm(arr, n):
    if len(arr) != n:
        print("NO 1")
    elif 1 not in arr:
        print("NO 2")
    elif arr.count(n) > 1:
        print("NO 3")
    else:
        for i in sorted(set(arr[1:])):
            if arr.count(i) > n-i+2:
                print("NO 4")
                break
        else:
            print("YES")
    
t = int(input())
while(t):
    n = int(input())
    arr = list(map(int, input().split()))
    is_perm(arr, n)
    t -= 1