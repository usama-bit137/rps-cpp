#include <iostream>
#include <cstdlib>
using namespace std; 

string userInputController();
string choiceChecker(string choice);

string choiceChecker(string choiceInput) {
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
  string choiceInput; 
  
  while(choiceInput != "r" && choiceInput != "p" && choiceInput != "s" ) {  
    cout << "Pick - r (rock), p (paper) or s (scissors): ";
    cin >> choiceInput;
  }
  
  return choiceInput;
}

string winLoseLogic(string userChoice, string computerChoice) {
  string verdict;
  if(userChoice == computerChoice) {
    verdict = "DRAW!!!";
  } else if (userChoice == "rock") {
    verdict = (computerChoice == "scissors") ? "You win :)" : "Computer Wins :(";
  } else if (userChoice == "paper") {
    verdict = (computerChoice == "rock") ? "You Win :)" : "Computer Wins :(";
  } else if (userChoice == "scissors") {
    verdict = (computerChoice == "paper") ? "You Win :)" : "Computer Wins :(";
  }
  return verdict;
}

int main() {
  // Sanitize user choice and checking: 
  string userChoice = userInputController();
  userChoice = choiceChecker(userChoice);
  cout << "You Chose: "<< userChoice << endl;

  // Computer choice: 
  // Random Package:
  int intComputerChoice = rand() % 3;
  string computerChoices[3] = {"r", "p", "s"};
  
  string stringComputerChoice = choiceChecker(computerChoices[intComputerChoice]);
  cout << "Computer Chose: " << stringComputerChoice << endl;

  cout << winLoseLogic(userChoice, stringComputerChoice);
}