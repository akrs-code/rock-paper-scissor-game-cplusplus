#include <iostream>
#include <conio.h> // Include for _getch()
#include <string>  // Include for string handling

using namespace std;

// Functions Declarations
void getPlayerNames(string &player1Name, string &player2Name);
char getPlayerChoice(const string &playerName);
void determineWinner(char player1, char player2, int &score1, int &score2, const string &player1Name, const string &player2Name);
void displayScores(int score1, int score2, const string &player1Name, const string &player2Name);

int main() {
    int score1 = 0, score2 = 0;
    char again;
    string player1Name, player2Name;

       cout << "****************** ROCK, PAPER, SCISSORS GAME ***********************" << endl;
        // Get player names
        getPlayerNames(player1Name, player2Name);
        cout << endl;

    do {

        // Call the function that get player choices
        char player1 = getPlayerChoice(player1Name);
        char player2 = getPlayerChoice(player2Name);
        cout << endl;

        // Display players' choices
        cout << player1Name << " chose: " << player1 << endl;
        cout << player2Name << " chose: " << player2 << endl;
        cout << endl;

        // Call the function that determine the winner
        determineWinner(player1, player2, score1, score2, player1Name, player2Name);
        cout << endl;

        // Call the function that display scores
        displayScores(score1, score2, player1Name, player2Name);
        cout << endl;

        // Ask if they want to play again
        cout << "Do you want to play again? (Y/N): ";
        cin >> again;
        cout << endl;

    } while (again == 'Y' || again == 'y');
        // Display final score if the players don't want to play anymore.
    cout << "Final Scores: " << player1Name << ": " << score1 << " | " << player2Name << ": " << score2 << endl;

    return 0;
}

// Function to get player names
void getPlayerNames(string &player1Name, string &player2Name) {
    cout << "Enter name for Player 1: ";
    cin >> player1Name;
    cout << "Enter name for Player 2: ";
    cin >> player2Name;
}

// Function to get a player's choice
char getPlayerChoice(const string &playerName) {
    char choice;
    cout << playerName << ": Choose rock (r/R), paper (p/P), or scissors (s/S): ";
    choice = _getch();
    cout << endl;

// Validate the choice
    while (choice != 'r' && choice != 'R' &&
           choice != 'p' && choice != 'P' &&
           choice != 's' && choice != 'S') {
        cout << "Invalid choice. Choose rock (r/R), paper (p/P), or scissors (s/S): ";
        choice = _getch();
        cout << endl;
    }

    return choice;
}

// Function to determine the winner of the round
void determineWinner(char player1, char player2, int &score1, int &score2, const string &player1Name, const string &player2Name) {
    if (player1 == player2) {
        cout << "It's a tie!" << endl;
    } else if ((player1 == 'r' || player1 == 'R') && (player2 == 's' || player2 == 'S')) {
        cout << player1Name << " wins!" << endl;
        score1++;
    } else if ((player1 == 'p' || player1 == 'P') && (player2 == 'r' || player2 == 'R')) {
        cout << player1Name << " wins!" << endl;
        score1++;
    } else if ((player1 == 's' || player1 == 'S') && (player2 == 'p' || player2 == 'P')) {
        cout << player1Name << " wins!" << endl;
        score1++;
    } else {
        cout << player2Name << " wins!" << endl;
        score2++;
    }
}

// Function to display the current scores of both players
void displayScores(int score1, int score2, const string &player1Name, const string &player2Name) {
    cout << "Current Scores: " << player1Name << ": " << score1 << " | " << player2Name << ": " <<
    score2 << endl;
}
