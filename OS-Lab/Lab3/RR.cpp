#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class RoundRobinScheduler {
    /*
    Metadata:
    Input:
    - Processes: A 2D vector where each inner vector contains:
        - Arrival Time (integer)
        - Burst Time (integer)
        - Process ID (integer)

    Output:
    - For each process, compute:
        1. Wait Time: The total time the process spends waiting in the ready queue.
        2. Turnaround Time: The total time taken from arrival to completion (Completion Time - Arrival Time).

    Description:
    - The Round Robin Scheduler implements the Round Robin scheduling algorithm to allocate CPU time to processes based on a fixed time quantum.
    - It sorts processes by arrival time and uses a queue to manage the execution order.
    - The scheduler processes each job for a maximum of the specified time quantum before moving to the next process.
    - If a process does not finish within the time quantum, it is pushed back to the queue for further execution.
    - The scheduler calculates waiting time and turnaround time for each process, storing them for final output.
    */
    private:
        // attributes
        int time_quantum;
        struct SortByArrivalTime
        {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        };
        queue<vector<int>> job_queue;
        vector<int> waitTime;
        vector<int> turnaroundTime;
        vector<int> burstTime;
        vector<int> pidStore;
        int completionTime = 0;

    public:
        // methods
        RoundRobinScheduler(int time) {
            time_quantum = time;
        }

        void Resize(int size) {
            turnaroundTime.resize(size, 0);
            waitTime.resize(size, 0);
        }

        void TakeProcesses(vector<vector<int>>& Processes) {
            sort(Processes.begin(), Processes.end(), SortByArrivalTime());
            for (int i = 0; i < Processes.size(); i++) {
                job_queue.push(Processes[i]);
                burstTime.push_back(Processes[i][1]);
                pidStore.push_back(Processes[i][2]);
            }
            // turnaround time = completion time - arrival time
            // waiting time = turnaround time - burst time
            Resize(pidStore.size());
            while (!job_queue.empty()) { 
                    vector<int> Process = job_queue.front();
                    job_queue.pop();

                    completionTime += min(time_quantum, Process[1]);
                    Process[1] -= time_quantum;
                    
                    if (Process[1] > 0) {
                        job_queue.push(Process);
                    } 
                    else {
                        turnaroundTime[Process[2] - 1] = completionTime - Process[0];
                        waitTime[Process[2] - 1] = turnaroundTime[Process[2] - 1] - burstTime[Process[2] - 1];
                    }
            }            
        }

        void PrintSchedule() {
            for (int i = 0; i < pidStore.size(); i++) {
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
    vector<vector<int>> Processes = {
        {0, 5, 1},
        {1, 3, 2},
        {2, 8, 3},
        {3, 6, 4}
    };
    int time_quantum = 2;
    RoundRobinScheduler scheduler(time_quantum); 
    scheduler.TakeProcesses(Processes);
    scheduler.PrintSchedule();
    return 0;
}