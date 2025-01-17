#include <bits/stdc++.h>
using namespace std;

int fifoPageFaults(int pages[], int n, int capacity) {
    unordered_set<int> s;
    queue<int> q;
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        if (s.find(pages[i]) == s.end()) {
            page_faults++;
            if (s.size() == capacity) {
                int val = q.front();
                q.pop();
                s.erase(val);
            }
            s.insert(pages[i]);
            q.push(pages[i]);
        }
    }
    return page_faults;
}

int lruPageFaults(int pages[], int n, int capacity) {
    unordered_set<int> s;
    unordered_map<int, int> lastUsed;
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        if (s.find(pages[i]) == s.end()) {
            page_faults++;
            if (s.size() == capacity) {
                int lru = INT_MAX, val;
                for (auto &entry : lastUsed) {
                    if (entry.second < lru) {
                        lru = entry.second;
                        val = entry.first;
                    }
                }
                s.erase(val);
            }
            s.insert(pages[i]);
        }
        lastUsed[pages[i]] = i;
    }
    return page_faults;
}

int lfuPageFaults(int n, int c, int pages[]) {
    int count = 0;
    vector<int> v;
    unordered_map<int, int> mp;
    int i;
    for (i = 0; i <= n - 1; i++) {
        auto it = find(v.begin(), v.end(), pages[i]);

        if (it == v.end()) {
            if (v.size() == c) {
                mp[v[0]]--;
                v.erase(v.begin());
            }
            v.push_back(pages[i]);
            mp[pages[i]]++;
            count++;
        } else {
            mp[pages[i]]++;
            v.erase(it);
            v.push_back(pages[i]);
        }

        int k = v.size() - 2;
        while (mp[v[k]] > mp[v[k + 1]] && k > -1) {
            swap(v[k + 1], v[k]);
            k--;
        }
    }
    return count;
}

int main() {
    int capacity;
    int choice;

    cout << "Enter the number of frames: ";
    cin >> capacity;

    cout << "Enter the number of pages: ";
    int n;
    cin >> n;
    int pages[n];

    cout << "Enter the page reference string (space separated): ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Choose Page Replacement Algorithm:\n";
    cout << "1. FIFO\n2. LRU\n3. LFU\n";
    cin >> choice;

    int page_faults = 0;
    switch (choice) {
        case 1:
            page_faults = fifoPageFaults(pages, n, capacity);
            cout << "FIFO Page Faults: " << page_faults << endl;
            break;
        case 2:
            page_faults = lruPageFaults(pages, n, capacity);
            cout << "LRU Page Faults: " << page_faults << endl;
            break;
        case 3:
            page_faults = lfuPageFaults(n, capacity, pages);
            cout << "LFU Page Faults: " << page_faults << endl;
            break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}
