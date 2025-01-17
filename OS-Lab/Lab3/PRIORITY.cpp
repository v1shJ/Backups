#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class PriorityQueueScheduling {
    /*
    Attributes:
    Data Structures:
    - Priority Queue: Manages processes based on priority levels.
    - Vectors: Stores waiting times, turnaround times, and process IDs.
    Process Representation: Each process is a vector containing:
    - Process ID (index 0)
    - Priority (index 1)
    - Arrival Time (index 2)
    - Burst Time (index 3)
    Key Methods:
    - TakeProcesses(): Sorts processes by arrival time and calculates waiting and turnaround times based on priority.
    - PrintSchedule(): Displays each process's ID, waiting time, and turnaround time.
    */
    private:
        struct SortByArrivalTime
        {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            }
        };

        struct SortByPriority 
        {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return a[1] > b[1];
            }
        };
        
        priority_queue<vector<int>, vector<vector<int>>, SortByPriority> ready_queue;
        vector<int> waitTime;
        vector<int> turnaroundTime;
        vector<int> pidStore;
        int completion_time = 0;

    public:
        void TakeProcesses(vector<vector<int>>& Processes) {
            sort(Processes.begin(), Processes.end(), SortByArrivalTime());
            
            int current_time = 0;
            ready_queue.push(Processes[0]);
            int i = 1;
            
            while (!ready_queue.empty() || i < Processes.size()) {

                if (ready_queue.empty() && i < Processes.size()) {
                    // If queue is empty but there are processes left to arrive, skip time
                    current_time = Processes[i][2];
                    ready_queue.push(Processes[i]);
                    i++;
                    continue;
                }

                vector<int> process = ready_queue.top();
                pidStore.push_back(process[0]);
                int burst_time = process[3];
                current_time = process[2];
                completion_time += burst_time;

                turnaroundTime.push_back(completion_time - current_time);
                if (waitTime.empty()) {
                    waitTime.push_back(0);
                } 
                else {
                    waitTime.push_back(turnaroundTime.back() - burst_time);
                }
                
                ready_queue.pop();
                current_time += burst_time;
                
                while (i < Processes.size() && Processes[i][0] <= current_time) {
                    ready_queue.push(Processes[i]);
                    i++;
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
    vector<vector<int>> processes = {
        {0, 2, 0, 5}, 
        {1, 1, 2, 3},  
        {2, 5, 4, 8},  
        {3, 4, 5, 6}   
    };

    PriorityQueueScheduling scheduler;
    scheduler.TakeProcesses(processes);
    scheduler.PrintSchedule();
    return 0;
}