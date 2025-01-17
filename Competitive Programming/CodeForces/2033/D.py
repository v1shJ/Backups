def counts(arr):
    s = 0
    indices = {0: -1}  
    count = 0
    last = -1 

    for i in range(len(arr)):
        s += arr[i]
            
        if s in indices:
            start = indices[s]
            if start >= last:
                count += 1
                last = i  
        indices[s] = i

    return count


for _ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))
    print(counts(li))