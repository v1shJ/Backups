#include <iostream>
#include <vector>

using namespace std;

int main() {
    #define n 5 // number of processes
    #define m 3 // number of resources

    vector<int> process; // Declare an empty vector for Process IDs
    for (int i = 0; i < n; ++i) {
        process.push_back(i); //  process IDs (0 to n-1)
    }
    //SAFE SETUP
        
    int alloc[n][m] = { { 0, 1, 0 }, // P0 // Allocation Matrix
                         { 2, 0, 0 }, // P1
                         { 3, 0, 2 }, // P2
                         { 2, 1, 1 }, // P3
                         { 0, 0, 2 } }; // P4

    int max[n][m] = { { 7, 5, 3 }, // P0 // MAX Matrix
                       { 3, 2, 2 }, // P1
                       { 9, 0, 2 }, // P2
                       { 2, 2, 2 }, // P3
                       { 4, 3, 3 } }; // P4

    //NOT SAFE SETUP

    /*int alloc[n][m] = { { 0, 1, 0 }, // P0
                         { 2, 0, 0 }, // P1
                         { 3, 0, 2 }, // P2
                         { 2, 1, 1 }, // P3
                         { 0, 0, 2 } }; // P4

    
    int max[n][m] = { { 7, 5, 3 }, // P0
                       { 3, 2, 2 }, // P1
                       { 9, 0, 2 }, // P2
                       { 4, 2, 2 }, // P3
                       { 5, 3, 3 } }; // P4
    */


    int need[n][m];//need= max-allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j]; 
        }
    }

    // available instances of each resource
    int available[m] = {3, 3, 2}; // safe setup

    //int available[m] = {2, 1, 0}; //not safe setup

    vector<int> work(m);
    for (int j = 0; j < m; j++) {
        work[j] = available[j]; 
    }

    vector<bool> finish(n, false); // Vector to record all the finished processes

   
    while (true) {
        bool progress = false; // informs about how whether processes have been completed in that iteration of the Process vector, so as to prevent infinite looping

        for (int i = 0; i < n; i++) {
            if (!finish[i]) { // If process i is not finished
                // Check if Need[i] <= Work
                bool canProceed = true; //assumed that it can proceed
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canProceed = false; //if need>work  then it cannot proceed
                        break;
                    }
                }

                if (canProceed) { // if it can proceed
                    progress = true; 
                    finish[i] = true; // Mark process as finished
                    // update work
                    for (int j = 0; j < m; j++) {
                        work[j] += alloc[i][j]; // Release allocated resources
                    }
                }
            }
        }

        if (!progress) {
            break; // max resource utilisation has been reached
        }
    }

    // Check if all processes are finished
    bool safeState = true;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            safeState = false; // Not all processes finished
            break;
        }
    }

    // output result
    if (safeState) {
        cout << "System is in a safe state." << endl;
    } else {
        cout << "System is not in a safe state." << endl;
    }

    return 0;
}

