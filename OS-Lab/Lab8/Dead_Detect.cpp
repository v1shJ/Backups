#include <iostream>
#include <vector>
#include <limits> // For numeric_limits
using namespace std;

class DeadlockDetection {
public:
    int numProcesses, numResources;
    vector<vector<bool>> request, allocation;
    vector<bool> visited, inStack;

    DeadlockDetection(int p, int r) : numProcesses(p), numResources(r) {
        request = vector<vector<bool>>(p, vector<bool>(r, false));
        allocation = vector<vector<bool>>(p, vector<bool>(r, false));
        visited = vector<bool>(p, false);
        inStack = vector<bool>(p, false);
    }

    void requestResource(int process, int resource) {
        request[process][resource] = true;
    }

    void allocateResource(int process, int resource) {
        allocation[process][resource] = true;
    }

    bool detectDeadlock(int process) {
        visited[process] = true;
        inStack[process] = true;

        // Check all resources
        for (int r = 0; r < numResources; ++r) {
            // If process is requesting resource and resource is allocated
            if (request[process][r] && allocation[process][r]) {
                for (int p = 0; p < numProcesses; ++p) {
                    if (!visited[p] && allocation[p][r] && detectDeadlock(p)) {
                        return true;
                    }
                }
            }
        }

        inStack[process] = false;
        return false;
    }

    bool isDeadlock() {
        visited.assign(numProcesses, false);
        inStack.assign(numProcesses, false);

        for (int i = 0; i < numProcesses; ++i) {
            if (!visited[i] && detectDeadlock(i)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int numProcesses, numResources;

    // Ensure correct input format
    cout << "Enter number of processes and resources: ";
    while (!(cin >> numProcesses >> numResources) || numProcesses <= 0 || numResources <= 0) {
        cout << "Invalid input. Please enter positive integers for processes and resources: ";
        cin.clear();  // clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    }

    DeadlockDetection dd(numProcesses, numResources);

    // Input the request matrix (read integers instead of bool)
    cout << "Enter request matrix (process x resources):\n";
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numResources; ++j) {
            int temp;
            while (!(cin >> temp) || (temp != 0 && temp != 1)) {
                cout << "Invalid input. Please enter 0 or 1: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            dd.request[i][j] = temp;
        }
    }

    // Input the allocation matrix (read integers instead of bool)
    cout << "Enter allocation matrix (process x resources):\n";
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numResources; ++j) {
            int temp;
            while (!(cin >> temp) || (temp != 0 && temp != 1)) {
                cout << "Invalid input. Please enter 0 or 1: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            dd.allocation[i][j] = temp;
        }
    }

    if (dd.isDeadlock()) {
        cout << "Deadlock detected!\n";
    } else {
        cout << "No deadlock detected.\n";
    }

    return 0;
}
