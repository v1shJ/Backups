#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Sequential Allocation
void sequentialAllocation(int fileSize, vector<int>& diskBlocks) {
    cout << "Sequential Allocation: File Size = " << fileSize << endl;
    for (int i = 0; i < fileSize; i++) {
        diskBlocks.push_back(i);
        cout << "Block " << i << " allocated." << endl;
    }
}

// Indexed Allocation
void indexedAllocation(int fileSize, vector<int>& diskBlocks, vector<int>& indexBlock) {
    cout << endl << "Indexed Allocation: File Size = " << fileSize << endl;
    for (int i = 0; i < fileSize; i++) {
        diskBlocks.push_back(i);
        indexBlock.push_back(i);
        cout << "Block " << i << " allocated. Index updated." << endl;
    }
}

// Linked Allocation
void linkedAllocation(int fileSize, vector<int>& diskBlocks) {
    cout << endl << "Linked Allocation: File Size = " << fileSize << endl;
    for (int i = 0; i < fileSize; i++) {
        diskBlocks.push_back(i);
        cout << "Block " << i << " allocated with pointer to next." << endl;
    }
}

int main() {
    int fileSize = 5;  // Example file size
    vector<int> diskBlocks;
    vector<int> indexBlock;

    // Sequential Allocation
    sequentialAllocation(fileSize, diskBlocks);

    // Indexed Allocation
    indexedAllocation(fileSize, diskBlocks, indexBlock);

    // Linked Allocation
    linkedAllocation(fileSize, diskBlocks);

    return 0;
}
