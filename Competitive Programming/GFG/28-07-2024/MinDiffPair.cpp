//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minDifference(int n, vector<int> &arr, int x) {
        // code here
        int mini = x+1;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                mini = min(mini, arr[i] ^ arr[j]);
            }
        }
        if(mini > x){
            return -1;
        }
        return mini;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        int x;
        scanf("%d", &x);

        Solution obj;
        int res = obj.minDifference(n, arr, x);

        cout << res << endl;
    }
}

// } Driver Code Ends