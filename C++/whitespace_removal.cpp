#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main(){
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
            outputFile << line << '\n';
        }

        inputFile.close();
        outputFile.close();

        std::cout << "Whitespace removal successful." << std::endl;
    } else {
        std::cout << "Error opening files." << std::endl;
    }
    return 0;
}
