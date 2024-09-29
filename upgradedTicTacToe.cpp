// Tic Tac Toe Game in C++

// Importing the necessary libraries
#include <iostream>
#include <limits> // Include limits for numeric_limits
using namespace std;

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Function to return the game status
int checkwin() {
    // Check horizontal, vertical, and diagonal wins
    for (int i = 1; i <= 7; i += 3) {
        if (square[i] == square[i + 1] && square[i + 1] == square[i + 2]) return 1;
    }
    for (int i = 1; i <= 3; i++) {
        if (square[i] == square[i + 3] && square[i + 3] == square[i + 6]) return 1;
    }
    if (square[1] == square[5] && square[5] == square[9]) return 1;
    if (square[3] == square[5] && square[5] == square[7]) return 1;

    // Check for draw
    if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' &&
        square[7] != '7' && square[8] != '8' && square[9] != '9') {
        return 0;
    }
    return -1;
}

// Function to draw the board
void board() {
    system("cls"); // Clear the console
    cout << "\n\n\tTic Tac Toe Game\n\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";

    // Drawing the board
    cout << "       |     |  \n";
    cout << "     " << square[1] << " |  " << square[2] << "  | " << square[3] << "\n";
    cout << "  _____|_____|_____\n";
    cout << "       |     |     \n";
    cout << "     " << square[4] << " | " << square[5] << "   | " << square[6] << "\n";
    cout << "  _____|_____|_____\n";
    cout << "       |     |     \n";
    cout << "     " << square[7] << " | " << square[8] << "   | " << square[9] << "\n";
    cout << "       |     |  \n";
}

// Function to validate user input
bool isValidMove(int choice) {
    return choice >= 1 && choice <= 9 && square[choice] == '0' + choice;
}

int main() {
    int player = 1, choice, i;

    do {
        board();
        char mark = (player == 1) ? 'X' : 'O'; // Determine the current player's mark
        cout << "Player " << player << ", enter the number (1-9): ";

        // Validate input
        while (true) {
            cin >> choice;

            // Check if input is valid
            if (cin.fail() || choice < 1 || choice > 9) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input! Please enter a number between 1 and 9: ";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
                break; // Valid input, exit the loop
            }
        }

        // Validate the move and update the board
        if (isValidMove(choice)) {
            square[choice] = mark;
        } else {
            cout << "Invalid Move! Try again.\n";
            continue; // Skip the rest of the loop
        }

        // Check the game status
        i = checkwin();
        player = (player % 2) + 1; // Switch player

    } while (i == -1); // Continue until there is a winner or a draw

    board(); // Display the final board

    if (i == 1) {
        cout << "\aCongratulations! Player " << (player == 1 ? 2 : 1) << " wins!\n";
    } else {
        cout << "\aGame Draw!\n";
    }
    cin.ignore();
    cin.get(); // Wait for user input before closing
    return 0;
}

