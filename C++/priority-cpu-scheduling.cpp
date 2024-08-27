//priority

#include <iostream>
#define SIZE 5
using namespace std;

int main() {
  int priority[SIZE] = {2, 6, 3, 5, 7};
  int arrival[SIZE] = {0, 1, 2, 4, 6};
  int burst[SIZE] = {3, 5, 4, 2, 9};
  int completionTime[SIZE] = {};
  int completed[SIZE] = {0, 0, 0, 0, 0};

  int currentTime = burst[0] + arrival[0];
  completionTime[0] = currentTime;
  completed[0] = -1;

  for (int i = 1; i <= SIZE; i++) {
    int idx = 1;
    while (arrival[idx] <= currentTime && idx <= SIZE) {
      idx++;
    }
    
    int lowestPriority = 100000;
    int lowestPriorityIdx = -1;
    for (int j = 1; j < idx; j++) {
      if (completed[j] != -1) {
        if (priority[j] < lowestPriority) {
          lowestPriority = priority[j];
          lowestPriorityIdx = j;
        }
      }
    }
    currentTime += burst[lowestPriorityIdx];
    completionTime[lowestPriorityIdx] = currentTime;
    completed[lowestPriorityIdx] = -1;
  }

  float waitingTime = 0;
  float turnaroundTime = burst[0];

  cout << "P_id " << "Priority " << "Arrival Time " << "Burst Time " << "Completion Time " << "Turnaround Time " << "Waiting Time " << '\n';
  for (int i = 1; i <= SIZE; i++) {
    cout << "  " << i << " \t  "  << priority[i - 1] << "\t  " << arrival[i - 1] << " \t\t" << burst[i - 1] << " \t  " << completionTime[i - 1]<< " \t\t" << completionTime[i - 1] - arrival[i - 1] << "\t\t" << completionTime[i - 1] - arrival[i - 1] - burst[i - 1] << '\n';
    waitingTime += completionTime[i - 1] - arrival[i - 1] - burst[i - 1];
    turnaroundTime += completionTime[i - 1] - arrival[i - 1];
  }

  cout << "Average waiting time: " << waitingTime / SIZE << '\n';
  cout << "Average turnaround time: " << turnaroundTime / SIZE << '\n';  

  return 0;
}