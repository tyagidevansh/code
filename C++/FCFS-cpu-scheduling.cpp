//fcfs

#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
  unordered_map<int, pair<int, int>> proc; //pid, arr, burst

  proc[1] = {0, 4};
  proc[2] = {1, 3};
  proc[3] = {2, 1};
  proc[4] = {3, 6};
  proc[5] = {4, 5};

  cout << "P_id " << "Arrival Time " << "Burst Time " << "Completion Time " << "Turnaround Time " << "Waiting Time " << '\n';

  float completionTime = 0, waitingTime = 0, turnaroundTime = 0 ;

  for (int i = 1; i <= proc.size(); i++) {
    completionTime += proc[i].second;
    cout << "  " << i << " \t  " <<proc[i].first << " \t\t" << proc[i].second << " \t  " << completionTime << " \t\t" << completionTime - proc[i].first << "\t\t" << completionTime - proc[i].first - proc[i].second << '\n';
    turnaroundTime += completionTime - proc[i].first; 
    waitingTime += completionTime - proc[i].first - proc[i].second;
  }

  cout << "Average waiting time: " << waitingTime / proc.size() << '\n';
  cout << "Average turnaround time: " << turnaroundTime / proc.size() << '\n';  

  return 0;
}