#include <iostream>
#include <string>
using namespace std;

int length_lcs(const string& A, string& B){
    int len_lcs = 0;
    for (size_t i = 0; i < A.length(); i++) {
        for (size_t j = 0; j < B.length(); j++) {
            if (A[i] == B[j]) {
                cout << B << endl;
                len_lcs++;
                B.erase(B.begin());
                cout << B << endl;
                break;
            }
        }
    }
    return len_lcs;
}

int main(){
    string A = "HOTDOG";
    string B = "HOTEL";

    cout << length_lcs(A, B);
}