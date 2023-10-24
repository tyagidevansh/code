#include <iostream>
#include <string>
using namespace std;

int length_lcs(const string& A, string& B){
    int len_lcs = 0;
    for (size_t i = 0; i < A.length(); i++) {
        for (size_t j = 0; j < B.length(); j++) {
            if (A[i] == B[j]) {
                len_lcs++;
                break;
            }
        }
        B.erase(B.begin());
    }
    return len_lcs;
}

int main(){
    string A = "CRINGE";
    string B = "ENGINE";

    cout << "Length of LCS: " << length_lcs(A, B);
}