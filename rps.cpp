#include <iostream>
using namespace std; 

string userInputController();
string choiceChecker(string choice);

string choiceChecker(string choiceInput) {
  // THIS WORKS ✅
  string choiceString;
  if (choiceInput=="r") {
    choiceString = "rock";
  } else if (choiceInput == "p") {
    choiceString = "paper";
  } else if (choiceInput == "s") {
    choiceString = "scissors";
  } else {
    choiceString = userInputController();
  }
  return choiceString;
}

string userInputController() {
  // THIS ALSO WORKS ✅
  string choiceInput; 
  while(choiceInput != "r" && choiceInput != "p" && choiceInput != "s" ) {  
    cout << "Pick - r (rock), p (paper) or s (scissors): ";
    cin >> choiceInput;
  }

  return choiceInput;
}

int main() {
  string choice = userInputController();
  choice = choiceChecker(choice);
  
  cout << choice << endl;
}