#include <iostream>
#include <string>

#define ROWS  3 //defining size of board
#define COLS  3

bool isWin(char board[ROWS][COLS], char turn);        // Function to check if there is a win condition on the 2D board
void printBoard(char board[ROWS][COLS]);   // Function to print the current state of the board
bool isValidMove(char board[ROWS][COLS], char turn, int x, int y);  // Function to validate the move
std::string menu();                              // Function to display the menu
void printHelp();                         // Function to print help when called 
void gameLoop();                          // Main game loop function


int main()
{
    //Menu Functionality
    while (0 != 1) {
        std::string userSelection = menu();

        if (userSelection == "Start")
        {
            gameLoop();
        }
        else if (userSelection == "Help") {

            printHelp();
        }
    }


    //outer loop will be for restarts, exit condition will be input of 'q', standing for exit
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
    if (board[0][0] == turn && board[0][1] == turn && board[0][2] == turn) // top row filled
        return true; 
    if (board[1][0] == turn && board[1][1] == turn && board[1][2] == turn) // second row filled
        return true;
    if (board[2][0] == turn && board[2][1] == turn && board[2][2] == turn) // third row filled
        return true;
    if (board[0][0] == turn && board[1][0] == turn && board[2][0] == turn) // first collumn filled
        return true;
    if (board[0][1] == turn && board[1][1] == turn && board[2][1] == turn) // second collumn filled
        return true;
    if (board[0][2] == turn && board[1][2] == turn && board[2][2] == turn) // third collumn filled
        return true;
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) // left diagonal filled
        return true;
    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) // right diagonal filled
        return true;

    return false; 
}
void printBoard(char board[ROWS][COLS])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            std::cout << "|" << board[i][j] << "|";
        std::cout << std::endl;

        if (i != 2) {
            std::cout << "---------" << std::endl;
        }
   }


}
bool isValidMove(char board[ROWS][COLS], char turn, int x, int y)
{
    if (x >= 0 && x <= 2) {
        return true;
    }
    else {
        return false; 
    }
}
std::string menu()
{
    //display menu screen
    int userChoice;
    std::cout << "Welcome to the BTS Tick Tack Toe" << std::endl << std::endl << std::endl;
    std::cout << "Please select an option by typing 1,2 or 3" << std::endl;
    std::cout << "(1) Start New Game" << std::endl;
    std::cout << "(2) Help " << std::endl;
    std::cout << "(3) Exit Game"<< std::endl; 

    //capture user selection
    while (0 != 1) {
        std::cin >> userChoice;

        if (userChoice == 1) {
            return "Start";
        }
        else if (userChoice == 2) {
            return "Help";
        }
        else if (userChoice == 3)
        {
            exit(0);
        }
        else {
            std::cout << "Please enter a valid choice" << std::endl;
        }
    }
}
void printHelp()
{
    //display the rules of tick tack toe
    int x;
    std::cout << "Rules of Tick Tack Toe" << std::endl << std::endl;
    std::cout << "1.The game is played on a grid that's 3 squares by 3 squares." << std::endl;
    std::cout << "2.One player is X, your friend is O . Players take turns putting their marks in empty squares." << std::endl;
    std::cout << "3.The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner." << std::endl;
    std::cout << "4.When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie." << std::endl;
    std::cout << "For more information go to https://www.exploratorium.edu/" << std::endl << std::endl << std::endl;

    std::cout << "Press 1 to return to the main screen" << std::endl; 
    std::cin >> x;

    //checks if user wants to leave screen
    if (x == 1)
    {
        return; 
    }

    //if the input isnt 1, the code will ask for a valid input
    while (x != 1)
    {
        std::cout << "Please enter a valid input" << std::endl;
        std::cin >> x;
        
        if (x == 1)
        {
          return;
        }
    }

}



