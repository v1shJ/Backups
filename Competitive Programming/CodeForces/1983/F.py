# def smallpair(arr, kj):
#     kmin = []
#     ind = []
#     for i in range(0, len(arr)-1):
#         kmin.append(arr[i] ^ arr[i+1])
#         ind.append([i, i+1])
#     for j in range(0, len(arr)-1):
#         for k in range(j+2, len(arr)):
#             li = arr[j:k+1]
#             kmin.append(min([li[x] ^ li[x+1] for x in range(len(li)-1)]))
#     print(kmin)

    


# n = int(input())
# for n0 in range(n):
#     a1 = list(map(int, input().split()))
#     a2 = list(map(int, input().split()))
#     smallpair(a2, a1[1])

def smallpair(arr, kj):
    kmin = []
    ind = []
    for i in range(0, len(arr)-1):
        kmin.append(arr[i] ^ arr[i+1])
        ind.append([i, i+1])
    for j in range(0, len(arr)-1):
        for k in range(j+2, len(arr)):
            li = arr[j:k+1]
            kmin.append(min([li[x] ^ li[x+1] for x in range(len(li)-1)]))
    print(sorted(kmin)[kj-1])
    print(sorted(kmin))

    


n = int(input())
for n0 in range(n):
    a1 = list(map(int, input().split()))
    a2 = list(map(int, input().split()))
    smallpair(a2, a1[1])