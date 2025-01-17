#include <iostream>
#include <vector>

using namespace std;

class FcfsScheduler {
    /*
    Metadata:
    Input: 
    - Process ID (integer)
    - Burst Time (integer)
    
    Output:
    - For each process, compute:
        1. Wait Time: Time the process waits in the ready queue before execution.
        2. Turnaround Time: Time taken from process arrival to completion (Wait Time + Burst Time).
        3. Average WaitTime and TurnAroundTime
    
    
    Description:
    - The scheduler implements the First-Come, First-Serve (FCFS) scheduling algorithm.
    - It takes a list of processes, each with a unique ID and burst time, and computes the waiting time and turnaround time.
    - The processes are executed in the order of their arrival (as given in the input list).
    */
    private:
        vector<int> waitTime;
        vector<int> turnaroundTime;
        vector<int> pidStore;
    
    public:
        void AddProcess(int pid, int burst_time) {
            pidStore.push_back(pid);

            if (waitTime.empty()) {
                waitTime.push_back(0);
            } else {
                waitTime.push_back(turnaroundTime.back());
            }

            turnaroundTime.push_back(waitTime.back() + burst_time);
        }

        void PrintSchedule() const {
            for (size_t i = 0; i < pidStore.size(); ++i) {
                cout << "Process ID: " << pidStore[i]
                     << " | Wait Time: " << waitTime[i]
                     << " | Turnaround Time: " << turnaroundTime[i] << "\n";
            }
            double total_turnaround_time = 0;
            double total_wait_time = 0;
            for(int i = 0; i < waitTime.size(); i++) {
                total_wait_time += waitTime[i];
            }
            for(int i = 0; i < turnaroundTime.size(); i++) {
                total_turnaround_time += turnaroundTime[i];
            }

            cout << "Average WaitTime: " << total_wait_time / waitTime.size() << "\n";
            cout << "Average TurnAroundTime: " << total_turnaround_time / turnaroundTime.size();
        }
};

int main() {
    FcfsScheduler scheduler;

    vector<vector<int>> processes = {
        {17, 83}, {5, 92}, {74, 3}, {45, 6}, {23, 1}, {98, 9},
        {62, 2}, {8, 54}, {36, 8}, {9, 41}
    };

    for (const auto &process : processes) {
        scheduler.AddProcess(process[0], process[1]);
    }

    scheduler.PrintSchedule();

    return 0;
}
