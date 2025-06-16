#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Process {
    string pid;
    int arrival, burst, remaining, finish, waiting, turnaround;
};

int main() {
    int quantum = 2;
    vector<Process> processes = {
        {"P1", 0, 7, 7},
        {"P2", 2, 4, 4},
        {"P3", 4, 1, 1},
        {"P4", 5, 4, 4}
    };

    int time = 0, completed = 0;
    queue<int> q;
    vector<bool> inQueue(processes.size(), false);
    float total_waiting = 0, total_turnaround = 0;
    string gantt = "";

    q.push(0);
    inQueue[0] = true;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        gantt += "| " + processes[i].pid + " " + to_string(time) + " - ";
        int run = min(quantum, processes[i].remaining);
        time += run;
        processes[i].remaining -= run;

        for (int j = 0; j < processes.size(); j++) {
            if (j != i && !inQueue[j] && processes[j].arrival <= time && processes[j].remaining > 0) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if (processes[i].remaining > 0) {
            q.push(i);
        } else {
            processes[i].finish = time;
            processes[i].turnaround = processes[i].finish - processes[i].arrival;
            processes[i].waiting = processes[i].turnaround - processes[i].burst;
            total_waiting += processes[i].waiting;
            total_turnaround += processes[i].turnaround;
            completed++;
        }

        gantt += to_string(time) + " ";
    }

    cout << "--- Round Robin (Quantum = " << quantum << ") ---\n";
    cout << "Gantt Chart: " << gantt << "|\n\n";
    cout << "Process\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto& p : processes)
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t" << p.waiting << "\t" << p.turnaround << "\n";

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << total_waiting / processes.size() << "\n";
    cout << "Average Turnaround Time: " << total_turnaround / processes.size() << "\n";
    return 0;
}
