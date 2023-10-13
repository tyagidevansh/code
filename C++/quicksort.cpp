#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int partition(vector<int>&arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(){
    vector<int> arr;
    string input;
    int value;

    cout << "Enter integers to add to the array (press ENTER to finish): ";

    while (getline(cin, input) && !input.empty()) {
        stringstream ss(input);
        while (ss >> value) {
            arr.push_back(value);
        }
    }
    
    int n = arr.size();

    cout << "Original array: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (auto it = arr.begin(); it != arr.end(); ++it){
        cout << *it << " ";
    }

    return 0;
}