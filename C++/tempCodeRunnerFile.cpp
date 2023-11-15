#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "hello world";

    int arr[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a']++;
    }

    char ch = 'l';

    cout<<"The count of ch is " << arr[ch-'a']<<endl;
    return 0;
}