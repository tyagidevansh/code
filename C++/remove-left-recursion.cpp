#include <iostream>
#include <vector>
#include <string>

void removeLeftRecursion(const std::string& nonTerminal, const std::vector<std::string>& rules) {
  std::vector<std::string> alpha; //recur
  std::vector<std::string> beta;  //non recur

  //split into recursive and non-recursive
  for (const auto& rule : rules) {
    if (rule.substr(0, nonTerminal.size()) == nonTerminal) {
      alpha.push_back(rule.substr(nonTerminal.size()));
    } else {
      beta.push_back(rule);
    }
  }

  if (alpha.empty()) {
    std::cout << "No left recursion found in " << nonTerminal << " -> ";
    for (const auto& rule : rules) {
      std::cout << rule << " | ";
    }
    std::cout << std::endl;
    return;
  }

  std::string newNonTerminal = nonTerminal + "'";

  std::cout << nonTerminal << " -> ";
  for (size_t i = 0; i < beta.size(); ++i) {
    std::cout << beta[i] << newNonTerminal;
    if (i < beta.size() - 1) {
      std::cout << " | ";
    }
  } 
  std::cout << std::endl;

  std::cout << newNonTerminal << " -> ";
  for (size_t i = 0; i < alpha.size(); ++i) {
    std::cout << alpha[i] << newNonTerminal << " | ";
  }
  std::cout << "E" << std::endl;

}

int main() {
  std::string nonTerminal = "A";
  std::vector<std::string> rules = {"Aa", "b"}; // A -> Aa | b

  removeLeftRecursion(nonTerminal, rules);

  return 0;
}