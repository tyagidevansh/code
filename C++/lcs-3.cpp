#include <iostream>
#include <string>
using namespace std;

int length_lcs(const string& A, string& B){
    int len_lcs = 0;
    int n = 0;
    
    for (size_t i = 0; i < A.length(); i++) {
        for (size_t j = n; j < B.length(); j++) {
            if (A[i] == B[j]) {
                len_lcs++;
                break;
            }
        }
        n++;
    }
    return len_lcs;
}

int main(){
    string A = "AquaVitae";
    string B = "AruTaVae";

    if (B.length() > A.length()){
        B.swap(A);
    }

    cout << "Length of LCS: " << length_lcs(A, B);
}




