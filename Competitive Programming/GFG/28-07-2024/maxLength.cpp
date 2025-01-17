#include <bits/stdc++.h>

using namespace std;

template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}

int typeshit(int n, vector<int> arr) {
    unordered_map<int, int> umap;
    int maxlen = -1;
    int sum = 0;

    umap[0] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        // adjust sum to match the problem requirement
        int adjustedsum = sum - (i + 1);

        if (umap.find(adjustedsum) != umap.end()) { // basically means if element exists in umap or not
            int startIndex = umap[adjustedsum];
            int length = i - startIndex;
            if (length > maxlen) {
                maxlen = length;
            }
        }
        
        // store the first occurrence of each adjustedsum
        if (umap.find(adjustedsum) == umap.end()) {
            umap[adjustedsum] = i;
        }
    }
    return maxlen;
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        cin >> arr;
        typeshit(n, arr);
    }
}