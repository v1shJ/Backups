#User function Template for python3
from collections import Counter

class Solution:
    def countUniques(self, a, k, l, r):
        # code here
        if(k == n):
            return r-l+1
        a = sorted(a)
        se = set(a)
        max_unq = len(se)
        c = Counter(a)
        real = c.most_common()
        
        while(k > 0 and max_unq != len(a)):
            for i in real:
                if i[1] > 1:
                    if(all(i in a for i in range(l, r+1))):
                        return int(max_unq)
                    else:
                        max_unq += 1
                        break
                    
            k -= 1
        return int(max_unq)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        k, l, r = map(int, input().strip().split())
        ob = Solution()
        ans = ob.countUniques(arr, k, l, r)
        print(ans)
        tc -= 1

# } Driver Code Ends