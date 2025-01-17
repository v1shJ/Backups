import os

print("Hello World")

sum = 0
for i in range(1, 1001):
    if i < 10:
        sum += 1
    elif i < 100:
        sum += 2
    elif i < 1000:
        sum += 3
    else:
        sum += 4
print(sum)


# Worst case efficienty of an algorithm is its efficiency for the worst-case input of size n, It guarantees that for any instance of size n, the running time will not exceed C(n), its running time on the worst-case inputs

# Best case efficiency of an algorithm is its efficiency for the best-case inpyt of size n. We determine the kind of inputs for which the count C(n) will be the smallest among all possible inputs of size n.

# Average Case Efficiency investigation is considerably more difficult than investigation of the worst-csae and best-case efficiency. The direct approach for doing this, involves dividing all instances of size n into several classes so that for each instance of the class the number of times the algorithm's basic operations is executed is the same. Then a probability distribution of inputs is obtained or assumed so that the expected value of the basic operation's count can be found! The average case efficiency cannot be obtained by taking the average of the worst and best-case efficiencies. There aer many important algorithms for which the average case efficiency is much better than the overly pessimistic worst-case efficiencies.

# AMORTIZED EFFICIENCY:
# This applies not to a single run of an algorithm but rather to a sequence of operations performed on the same data structue. It turns out that in some situations a single operation can be expensive, but the total time for an entire sequence of n such operations is always significantly better than the worst-case efficiency of that single operation multiplied by n. 
# So we can amortize the high cost of such a worst-case occurrence over the entire sequence in a manner similar to the way a business would amortize the cost of an expensive item over the years of the item's productive life
# Basically, provides a guarantee that the average-case time complexity of an operation is constant, even if some operations may be expensive.

def vmergesort(arr, l, r):
    countinv = 0
    if l < r:
        mid = (l + r)//2
        countinv += vmergesort(arr, l, mid)
        countinv += vmergesort(arr, mid+1, r)
        countinv += vcount(arr, l, mid, r)
    return countinv

def vcount(arr, l, mid, r):
    left = arr[l : mid+1]
    right = arr[mid+1 : r+1]
    i, j, k = 0, 0, l
    countinv = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
            countinv += len(left)-i # or even mid-i-1
        k += 1
    while i < len(left):
        arr[k] = left[i]
        k += 1
        i += 1
    while j < len(right):
        arr[k] = right[j]
        k += 1
        j += 1
    return countinv
    

def vmerge(arr, l, mid, r):
    left, right = arr[l : mid + 1], arr[mid + 1 : r+1]
    k = l
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1
    
    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1
    # that's about it folks


def f(n):
    if n < 2:
        return 1
    return f(n-1)*n

def binary(n):
    if n == 0: return 0
    
    binary(n//2)
    print(n%2, end="")



if __name__ == "__main__":
    # print(f(5))
    # binary(10)
    print()
    unsorted_arr = [3, 1, 5, 4, 7, 6, 2, 9]
    print(vmergesort(unsorted_arr, 0, len(unsorted_arr)-1))
    