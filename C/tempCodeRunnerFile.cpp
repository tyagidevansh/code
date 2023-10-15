#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; //choose the last element at the pivot
    int i = (low -1); //index of the smaller element

    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(vector<int>&arr, int low, int high) {
    if (lw < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    vector<int> v;
    string input;
    int value;

    cout<<"ENter val ";

    while(getline(cin, input) && !input.empty()){
        stringstream ss(input);
        while (ss >> value) {
            v.push_back(value);
        }
    }

    int n = v.size();

    quickSort(v, 0 , n-1);
}