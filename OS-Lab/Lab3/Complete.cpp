#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <numeric>
#include <tuple>
using namespace std;

struct CompareByBurstTime {
   // For SJF scheduling
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;  
    }
};

struct CompareByPriority {
   // For priority scheduling
    bool operator()(const tuple<int, int, int>& p1, const tuple<int, int, int>& p2) {
        return get<2>(p1) > get<2>(p2);  
    }
};


void fcfs_algorithm(vector<pair<int, int>> processes) {
      queue<pair<int, int>> q;
      vector<int> wait_times, turnaround_times;
      int current_time = 0;
      
      for (int i = 0; i < processes.size(); i++) q.push(processes[i]);
      
      while (!q.empty()) {
           pair<int, int> process = q.front();
           q.pop();
         
           int process_id = process.first;
           int burst_time = process.second;
         
           wait_times.push_back(current_time);
           turnaround_times.push_back(current_time + burst_time);
           current_time += burst_time;
        
           cout << "Process " << process_id << " completed." << endl;
      }
      
      int total_wait_time = accumulate(wait_times.begin(), wait_times.end(), 0);
      double average_wait_time = static_cast<double>(total_wait_time) / wait_times.size();
      cout << "Average wait time: " << average_wait_time << endl;
      
      int total_turnaround_time = accumulate(turnaround_times.begin(), turnaround_times.end(), 0);
      double average_turnaround_time = static_cast<double>(total_turnaround_time) / turnaround_times.size();
      cout << "Average turnaround time: " << average_turnaround_time << endl << endl;
}

void sjf_algorithm(vector<pair<int, int>> process) {
      priority_queue< pair<int, int>, vector<pair<int, int>>, CompareByBurstTime > pq;
      vector<int> wait_times, turnaround_times;
      int current_time = 0;
      
      for (const auto& p : process) pq.push(p);
      
      while (!pq.empty()) {
           pair<int, int> process = pq.top();
           pq.pop();
         
           int process_id = process.first;
           int burst_time = process.second;
         
           wait_times.push_back(current_time);
           turnaround_times.push_back(current_time + burst_time);
           current_time += burst_time;
         
           cout << "Process " << process_id << " completed." << endl;
      }
      
      int total_wait_time = accumulate(wait_times.begin(), wait_times.end(), 0);
      double average_wait_time = static_cast<double>(total_wait_time) / wait_times.size();
      cout << "Average wait time: " << average_wait_time << endl;
      
      int total_turnaround_time = accumulate(turnaround_times.begin(), turnaround_times.end(), 0);
      double average_turnaround_time = static_cast<double>(total_turnaround_time) / turnaround_times.size();
      cout << "Average turnaround time: " << average_turnaround_time << endl << endl;
}

void round_robin(vector<pair<int, int>> processes, int time_slice) {
    queue<pair<int, int>> q;
    vector<int> remaining_burst_time(processes.size()), 
                wait_times(processes.size(), 0), 
                turnaround_times(processes.size());
    int total_time = 0;

    for (int i = 0; i < processes.size(); i++) {
        q.push({i, processes[i].second}); 
        remaining_burst_time[i] = processes[i].second;
    }

    vector<bool> in_queue(processes.size(), true); 

    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int index = p.first;                
        int burst_time = remaining_burst_time[index]; 

        if (burst_time <= time_slice) {
            total_time += burst_time;
            turnaround_times[index] = total_time;
            cout << "Process " << processes[index].first << " completed at time " << total_time << endl;
            in_queue[index] = false; 
        } else {
            total_time += time_slice;
            remaining_burst_time[index] -= time_slice;
            q.push({index, remaining_burst_time[index]}); 
        }

        for (int i = 0; i < processes.size(); i++) {
            if (in_queue[i] && i != index && remaining_burst_time[i] > 0) {
                wait_times[i] += min(time_slice, burst_time);
            }
        }
    }

    int total_wait_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < processes.size(); i++) {
        total_wait_time += wait_times[i];
        total_turnaround_time += turnaround_times[i];
    }

    double average_wait_time = static_cast<double>(total_wait_time) / processes.size();
    double average_turnaround_time = static_cast<double>(total_turnaround_time) / processes.size();

    cout << "Average wait time: " << average_wait_time << endl;
    cout << "Average turnaround time: " << average_turnaround_time << endl << endl;
}


void priority_scheduling(vector<tuple<int, int, int>> process) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareByPriority> pq;
    vector<int> wait_times, turnaround_times;
    int current_time = 0;

    for (const auto& p : process) pq.push(p);

    while (!pq.empty()) {
        tuple<int, int, int> p = pq.top();
        pq.pop();

        int process_id = get<0>(p);
        int burst_time = get<1>(p);

        wait_times.push_back(current_time);
        turnaround_times.push_back(current_time + burst_time);
        current_time += burst_time;

        cout << "Process " << process_id << " completed." << endl;
    }

    int total_wait_time = accumulate(wait_times.begin(), wait_times.end(), 0);
    double average_wait_time = static_cast<double>(total_wait_time) / wait_times.size();
    cout << "Average wait time: " << average_wait_time << endl;

    int total_turnaround_time = accumulate(turnaround_times.begin(), turnaround_times.end(), 0);
    double average_turnaround_time = static_cast<double>(total_turnaround_time) / turnaround_times.size();
    cout << "Average turnaround time: " << average_turnaround_time << endl;
}


int main() {
   vector<pair<int, int>> v;
   v.push_back(make_pair(1, 2));
   v.push_back(make_pair(2, 3));
   v.push_back(make_pair(3, 5));
   v.push_back(make_pair(4, 4));
   v.push_back(make_pair(5, 6));
   
   cout<<"FCFS Algorithm:"<<endl;
   fcfs_algorithm(v);
   
   cout<<"SJF Algorithm:"<<endl;
   sjf_algorithm(v);
   
   cout<<"Round Robin algorithm:"<<endl;
   round_robin(v, 2);
   
   cout<<"Priority algorithm:"<<endl;
   vector<tuple<int, int, int>> processes = { {1, 6, 2}, {2, 8, 1}, {3, 7, 3}, {4, 3, 2} };
   priority_scheduling(processes);
   return 0;
}