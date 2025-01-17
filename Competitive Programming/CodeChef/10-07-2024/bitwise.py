# cook your dish here

def find(arr):
    a = arr[0]
    for i in arr[1:]:
        a |= i
    return a
    
def real(arr):
    li = arr
    li.sort()
    count = 0
    typesh = [(2 ** i) - 1 for i in range(0, 20)]
    while(find(li) not in typesh):
        if len(li) != 1:
            li.pop()
            count += 1
            continue
        count += 1
        break
    print(count)
    
n = int(input())
for i in range(n):
    size = int(input())
    li = list(map(int, input().split()))
    real(li)