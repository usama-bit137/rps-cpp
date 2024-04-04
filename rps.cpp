#include <iostream>
#include <algorithm>
using namespace std; 

string userInputController();
string characterChecker(string choice);

string characterChecker(string choice) {
  string choiceString;
  if (choice=="r") {
    choiceString = "rock";
  } else if (choice == "p") {
    choiceString = "paper";
  } else if (choice == "s") {
    choiceString = "scissors";
  } else {
    choiceString = userInputController();
  }
  return choiceString;
}

string  userInputController() {
  string choice; 
  cout << "Pick - rock (r), paper (p) or scissors (s): ";
  cin >> choice;
  if (choice.length() == 1) {
    choice = characterChecker(choice);
  } 
  return choice; 
}

int main() {
  // pick r,ps: 
  string choice = userInputController(); 
  cout << choice << endl;
}