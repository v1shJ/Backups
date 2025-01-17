def a(n):
    arr = [really+1 for really in range(n)]
    # for i in range(n-1, 0, -1):
    #     sum = 0
    #     while(sum%i != 0):
    #         for j in range(i, n-1):
    #             if j%i == 0:
    #                 sum += arr[j]
    #         if sum%i == 0:
    #             continue
            
    #         arr[i]+=1
    for i in arr:
        print(i, end = " ")

n = int(input())
for i in range(n):
    j = int(input())
    a(j)
    print()