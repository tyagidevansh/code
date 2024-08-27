//sjs

#include <iostream>
#define SIZE 5
using namespace std;

int main() {
  int arrivalTimes[SIZE] = {1, 3, 6, 7, 9};
  int burstTimes[SIZE] = {7, 3, 2, 10, 8};
  int completionTime[SIZE] = {};
  int completed[SIZE] = {0, 0, 0, 0, 0};
  int idx = -1;

  int currentTime = burstTimes[0] + arrivalTimes[0];
  completionTime[0] = burstTimes[0] + arrivalTimes[0];
  completed[0] = -1;

  for (int i = 1; i <= SIZE; i++) {
    int idx = 1;
    while (arrivalTimes[idx] <= currentTime) {
      idx++;
    }
    int shortestJob = 1000000;
    int shortestJobIdx = -1;
    for (int j = 1; j <= idx; j++){
      if (completed[j] != -1) {
        if (burstTimes[j] < shortestJob) {
          shortestJob = burstTimes[j];
          shortestJobIdx = j;
        }
      }
    }
    currentTime += shortestJob;
    completionTime[shortestJobIdx] = currentTime;
    completed[shortestJobIdx] = -1;
  }

  float waitingTime = 0;
  float turnaroundTime = burstTimes[0];
  
  cout << "P_id " << "Arrival Time " << "Burst Time " << "Completion Time " << "Turnaround Time " << "Waiting Time " << '\n';
  
  for (int i = 1; i <= SIZE; i++) {
    cout << "  " << i << " \t  " << arrivalTimes[i - 1] << " \t\t" << burstTimes[i - 1] << " \t  " << completionTime[i - 1]<< " \t\t" << completionTime[i - 1] - arrivalTimes[i - 1] << "\t\t" << completionTime[i - 1] - arrivalTimes[i - 1] - burstTimes[i - 1] << '\n';
    waitingTime += completionTime[i - 1] - arrivalTimes[i - 1] - burstTimes[i - 1];
    turnaroundTime += completionTime[i - 1] - arrivalTimes[i - 1];
  }

  cout << "Average waiting time: " << waitingTime / SIZE << '\n';
  cout << "Average turnaround time: " << turnaroundTime / SIZE << '\n';  

  return 0;
}