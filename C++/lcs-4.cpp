#include <iostream>
#include <string>
#include <chrono>
using namespace std;

int length_lcs(const string& text1, const string& text2, int i, int j){

    if (i == 0 || j == 0){
        return 0;
    }
    if (text1[i-1] == text2[j-1]) {
        return 1 + length_lcs(text1, text2, i-1, j-1);
    } else {
        int without_i = length_lcs(text1, text2, i - 1, j);
        int without_j = length_lcs(text1, text2, i, j - 1);
        return max(without_i, without_j);
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    string text1 = "mhunuzqrkzsnidwbun";
    string text2 = "szulspmhwpazoxijwbq";

    int length = length_lcs(text1, text2, text1.length(), text2.length());

    cout << "Length of Longest Common Subsequence: " << length << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}