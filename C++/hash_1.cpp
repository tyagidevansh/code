#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main() {
    string s = "hello world";

    auto start = chrono::high_resolution_clock::now();
    int arr[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a']++;
    }

    char ch = 'l';

    cout<<"The count of ch is " << arr[ch-'a']<<endl;
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Running time using hash table : " << duration.count() << " microseconds" << endl;

    return 0;
}