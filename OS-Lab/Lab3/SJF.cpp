#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class SjfScheduler {
    /*
    This is a class that calculates the order of each process 
    based on its job (burst) time. The processes that take 
    lesser time will occur first
    Attributes:
    sort: this structure is used as a parameter in the sorting
         algorithm it sorts according to the arrival time

    ready_queue: this is a minimum priority queue that stores each 
        job on the basis of the burst time 

    waitTime: stores the waiting_times
    turnAroundTime: stores the turn_around_times
    pidStore: stores the Process ID

    Functions:
    TakeProcesses: takes a 2D vector where each vector contains:
        the arrival time
        the burst time 
        the process ID
    
    PrintSchedule: this prints the final schedule decided using the 
        SJF algorithm
    */
    private:
        struct SortByArrivalTime
        {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        };

        struct SortByBurstTime 
        {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return a[1] > b[1];
            }
        };
        
        priority_queue<vector<int>, vector<vector<int>>, SortByBurstTime> ready_queue;
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
                    current_time = Processes[i][0];
                    ready_queue.push(Processes[i]);
                    i++;
                    continue;
                }

                vector<int> process = ready_queue.top();
                pidStore.push_back(process[2]);
                int burst_time = process[1];
                current_time = process[0];
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
    vector<vector<int>> Processes = {
        {0, 5, 1},
        {1, 3, 2},
        {2, 8, 3},
        {3, 6, 4}
    };
    SjfScheduler scheduler; 
    scheduler.TakeProcesses(Processes);
    scheduler.PrintSchedule();
    return 0;
}