#include <iostream>
#include <cstdlib>
using namespace std; 

string playerInputController();
string choiceChecker(string choice);
int winLoseLogic(string playerChoice, string computerChoice);
int game(); 

int main() {
  
  int numGames;
  cout << "How many games do you want to play?: " << endl;
  cin >> numGames;
  int playerScore = 0, computerScore = 0; 
  
  for (int i = 1; i <= numGames; ++i){
    cout << "ROUND " << i << endl;
    int score = game();
    if (score < 0) {
      ++computerScore;
      cout << "Computer Wins This Round You Fool!!!" << endl;
    } else if (score > 0) {
      ++playerScore;
      cout << "You Win This Time, But Next Time We Shall See!!!" << endl;
    } else {
      cout << "It's A Draw!" << endl;
    }
  }

  string winner = ( playerScore > computerScore ) ? "Blast It! You Won!" : "SUCKERRRRRR!!!";
  cout << winner << endl;    

}

string choiceChecker(string choiceInput) {
  string choiceString;
  
  if (choiceInput=="r") {
    choiceString = "rock";
  } else if (choiceInput == "p") {
    choiceString = "paper";
  } else if (choiceInput == "s") {
    choiceString = "scissors";
  } else {
    choiceString = playerInputController();
  }
  
  return choiceString;
}

string playerInputController() {
  string choiceInput; 
  
  while(choiceInput != "r" && choiceInput != "p" && choiceInput != "s" ) {  
    cout << "Pick - r (rock), p (paper) or s (scissors): ";
    cin >> choiceInput;
  }
  
  return choiceInput;
}

int winLoseLogic(string playerChoice, string computerChoice) {
  int verdict;
  
  if(playerChoice == computerChoice) {
    verdict = 0;
  } else if (playerChoice == "rock") {
    verdict = (computerChoice == "scissors") ? 1  : -1;
  } else if (playerChoice == "paper") {
    verdict = (computerChoice == "rock") ? 1: -1;
  } else if (playerChoice == "scissors") {
    verdict = (computerChoice == "paper") ? 1 : -1;
  }
  return verdict;

}

int game() {
  string playerChoice = playerInputController();
  playerChoice = choiceChecker(playerChoice);
  cout << "You Chose: "<< playerChoice << endl;

  int intComputerChoice = rand() % 3;
  string computerChoices[3] = {"r", "p", "s"};
  
  string stringComputerChoice = choiceChecker(computerChoices[intComputerChoice]);
  cout << "Computer Chose: " << stringComputerChoice << endl;

  return winLoseLogic(playerChoice, stringComputerChoice);
}
