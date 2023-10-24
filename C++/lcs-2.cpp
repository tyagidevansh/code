#include <iostream>
#include <cstring>
using namespace std;

void remove_char(char B[]){
    size_t len = strlen(B);

    if (len > 0){
        for (int i = 0; i < len; i++){
            B[i] = B[i + 1]; 
        }
    }
    B[len - 1] = '\0'; 
}

int lcs(char A[], char B[]){
    int len_lcs = 0;
    for (size_t i = 0; i < strlen(A); i++){
        for (size_t j = 0; j < strlen(B); j++){
            if (A[i] == B[j]){
                len_lcs++;
                remove_char(B);
                break;
            }
        }
    }
    return len_lcs;
}

int main(){
    char A[] = "ABDEFGHI";
    char B[] = "BDFGI";

    cout << lcs(A, B);

}