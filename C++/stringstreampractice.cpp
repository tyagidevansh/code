//string stream

#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int countWords(string str){
    stringstream s(str); //create a stringstream object with string str
    string word; //declare a variable 'word'
 
    int count = 0;
    while (s >> word)
        count++;
    return count;
}

void printFrequency(string str){
    map <string, int> FW;

    stringstream ss(str);

    string Word;

    while (ss >> Word) FW[Word]++;

    for (auto it = FW.begin(); it != FW.end(); it++){
        cout << it-> first << " -> " << it -> second << "\n";
    }
}

string int_to_str(int val) {
    stringstream x;

    x << val;

    string str;
    x >> str;

    return str;
}
int main(){
    string str = "hello world world hello huh ?? nah bruv yo yo";
    //cout << "Number of words in the string: " << countWords(str) << endl;
    //printFrequency(str);
    //cout  << int_to_str(123);

    
    return 0;
}

