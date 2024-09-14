#include <iostream>

#define ROWS  3 //defining size of board
#define COLS  3

bool isWin(char board[ROWS][COLS], char turn);        // Function to check if there is a win condition on the 2D board
void printBoard(char board[ROWS][COLS]);   // Function to print the current state of the board
bool isValidMove(char board[ROWS][COLS], char turn, int x, int y);  // Function to validate the move
void menu();                              // Function to display the menu
void printHelp();                         // Function to print help when called 
void gameLoop();                          // Main game loop function


int main()
{
    //Menu section
    menu();
    //Exit menu section

    //outer loop will be for restarts, exit condition will be input of 'e', standing for exit
    char input = ' ';
    while (input != 'q')
    {
        /* TODO: need conditional logic that allows end of game or restart or if input is incorrect and must to re-entered*/
        std::cin >> input;
    }
    std::cout << "Thank you for playing" << std::endl;
    return 0;
}

void gameLoop() {
    char board[ROWS][COLS] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };  // Initialize 2D array
    char turn = 'X';  // X starts the game
    int turn_count = 0;
    bool isFinished = false;

    printBoard(board);  // Display the initial empty board

    while (!isFinished && turn_count < 9) {  // Game ends when the board is full or someone wins

        /* Add condition logic for user input for other commands, for example:
            std::cout << please choose an option: q (quit), c (continue turn), h (help);
            std::cin << input;

            switch case statement for all possible outcomes - Note: below  logic will probably need to be encapsulated in one of the conditions
        */

        int x, y;  // Coordinates for the user's move
        std::cout << turn << "'s turn. Enter your move (row and column): ";
        std::cin >> x >> y;

        if (isValidMove(board, turn, x, y)) {
            board[x][y] = turn;  // Place the current player's mark on the board
            turn_count++;  // Increment turn counter
            printBoard(board);  // Print the board after the move

            if (isWin(board, turn)) {  // Check for win condition
                std::cout << turn << " wins the game!\n";
                isFinished = true;
            }
            else {
                // Switch turn between 'X' and 'O'
                turn = (turn == 'X') ? 'O' : 'X';
            }
        }
        else {
            std::cout << "Invalid move. Try again.\n";
        }
    }

    if (!isFinished) {
        std::cout << "The game is a tie!\n";
    }
}

bool isWin(char board[ROWS][COLS], char turn)
{
    return 1;
}
void printBoard(char board[ROWS][COLS])
{
    //enter logic here
}
bool isValidMove(char board[ROWS][COLS], char turn, int x, int y)
{
    return 1;
}
void menu()
{
    //enter logic here
}
void printHelp()
{
    //enter logic here
}



