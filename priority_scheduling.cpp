#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Process {
    string pid;
    int arrival, burst, priority;
    int start = 0, finish = 0, waiting = 0, turnaround = 0;
    bool completed = false;

    // Constructor for initialization
    Process(string id, int a, int b, int p) {
        pid = id;
        arrival = a;
        burst = b;
        priority = p;
    }
};

int main() {
    vector<Process> processes;

    // Add processes using constructor
    processes.push_back(Process("P1", 0, 7, 2));
    processes.push_back(Process("P2", 2, 4, 1));
    processes.push_back(Process("P3", 4, 1, 3));
    processes.push_back(Process("P4", 5, 4, 2));

    int time = 0, completed = 0;
    float total_waiting = 0, total_turnaround = 0;
    vector<string> gantt;

    while (completed < (int)processes.size()) {
        int idx = -1;
        int highest_priority = 1e9;

        for (int i = 0; i < (int)processes.size(); i++) {
            if (!processes[i].completed && processes[i].arrival <= time) {
                if (processes[i].priority < highest_priority) {
                    highest_priority = processes[i].priority;
                    idx = i;
                } else if (processes[i].priority == highest_priority) {
                    if (processes[i].arrival < processes[idx].arrival) {
                        idx = i;
                    }
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        processes[idx].start = time;
        processes[idx].finish = time + processes[idx].burst;
        processes[idx].waiting = processes[idx].start - processes[idx].arrival;
        processes[idx].turnaround = processes[idx].finish - processes[idx].arrival;

        time = processes[idx].finish;
        processes[idx].completed = true;
        completed++;

        total_waiting += processes[idx].waiting;
        total_turnaround += processes[idx].turnaround;
        gantt.push_back("| " + processes[idx].pid + " " + to_string(processes[idx].start) + " - " + to_string(processes[idx].finish) + " ");
    }

    cout << "--- Priority Scheduling (Non-Preemptive) ---\nGantt Chart: ";
    for (const auto& g : gantt) cout << g;
    cout << "|\n\nProcess\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t" << p.priority << "\t\t"
             << p.waiting << "\t" << p.turnaround << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << total_waiting / processes.size() << "\n";
    cout << "Average Turnaround Time: " << total_turnaround / processes.size() << "\n";
    return 0;
}
