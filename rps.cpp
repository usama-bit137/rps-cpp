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
  cout << "Pick - rock (r), paper (p) or scissors (s): ";
  cin >> choiceInput;

  if (choiceInput.length() == 1) {
    choiceInput = choiceChecker(choiceInput); 
  }

  return choiceInput;
}

int main() {
  // pick r,p,s:
  string choice = userInputController();
  cout << choice << endl;

  // PROBLEM 💥: 
  /*
  At this point, single characters should be 
  */
  // while(choice != "rock" || choice != "paper" || choice != "scissors") {
  //   choice = userInputController();
  // }
}