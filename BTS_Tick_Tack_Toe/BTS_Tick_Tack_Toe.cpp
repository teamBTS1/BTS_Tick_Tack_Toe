#include <iostream>
#include <string>

#define ROWS  3 //defining size of board
#define COLS  3

bool isWin(char board[ROWS][COLS], char turn);        // Function to check if there is a win condition on the 2D board
void printBoard(char board[ROWS][COLS]);   // Function to print the current state of the board
bool isValidMove(char board[ROWS][COLS], char turn, int x, int y);  // Function to validate the move
void clearBadInput();                               //Function to clear any bad input (strings) from cin
std::string menu();                              // Function to display the menu
void printHelp();                         // Function to print help when called 
char gameLoop();                          // Main game loop function and returns winner for stat keeping
void displayWins(int x, int o);                    //Displays amount of wins by each side


int main()
{
    //Menu Functionality
    int loop = 1, xWins = 0, oWins = 0;
    char winner;
    while (0 != loop) {
        std::string userSelection = menu();

        if (userSelection == "Start")
        {
            std::cout << "Input 9 9 to quit your current game of tic tac toe at any time." << std::endl << std::endl;
            winner = gameLoop(); // When the game ends, it will jump back out at this point.  After this if else, should be when you ask if they want to replay quit ect.  
            if (winner == 'X') //Handles updating winner count
            {
                xWins += 1;
            }
            else if (winner == 'O')
            {
                oWins += 1;
            }
        }
        else if (userSelection == "Help") {

            printHelp();
        }
        else if (userSelection == "Wins")
        {
            displayWins(xWins, oWins);
        }
        else if(userSelection == "badInput") {
            std::cout << std::endl << "Please enter a valid choice." << std::endl << std::endl;
        }
    }    
}

void clearBadInput() //Function to clear bad input such as strings
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char gameLoop() {
    char board[ROWS][COLS] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };  // Initialize 2D array
    char turn = 'X';  // X starts the game
    int turn_count = 0;
    bool isFinished = false;
    bool isQuit = false;

    printBoard(board);  // Display the initial empty board

    while (!isFinished && turn_count < 9 && !isQuit) {  // Game ends when the board is full or someone wins or q is entered to quit

        int x, y;  // Coordinates for the user's move
        std::cout << turn << "'s turn. Enter your move (row and column): ";
        std::cin >> x >> y;
        if (x == 9 || y == 9) //Checks if q was entered to quit game
        {
            isQuit = true;
            isFinished = true;
        } 
        else {
            if (isValidMove(board, turn, x, y)) {
                board[x][y] = turn;  // Place the current player's mark on the board
                turn_count++;  // Increment turn counter
                printBoard(board);  // Print the board after the move

                if (isWin(board, turn)) {  // Check for win condition
                    std::cout << turn << " wins the game!\n";
                    return turn;
                    isFinished = true;
                }
                else {
                    // Switch turn between 'X' and 'O'
                    turn = (turn == 'X') ? 'O' : 'X';
                }
            }
            else {
                clearBadInput();
                std::cout << "Invalid move. Try again.\n";
            }
        }    
    }

    if (!isFinished) {
        std::cout << "The game is a tie!\n";
        return 'T';
    }
}

void displayWins(int x, int o)
{
    std::cout << "X has " << x << " wins." << std::endl;
    std::cout << "O has " << o << " wins." << std::endl << std::endl;
}

bool isWin(char board[ROWS][COLS], char turn)
{
    //checks for various win conditions
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
    //loops through the 2d board printing out the values
    std::cout << std::endl; //Adds spacing to make neater
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            std::cout << "|" << board[i][j] << "|";
        std::cout << std::endl;

        if (i != 2) {
            std::cout << "---------" << std::endl;
        }
   }
    std::cout << std::endl; //Adding spacing to make neater
}
bool isValidMove(char board[ROWS][COLS], char turn, int x, int y)
{
   
    if (x < 0 || y < 0) //Checks if string is entered or bad input
    {
        return false;
    }

    if (x >= 0 && x <= 2)         //checks to make sure the move is within bounds of the game, and spot is not occupied by an X or O
    {
        if (y >= 0 && y <= 2)
        {
            if (board[x][y] == ' ')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
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
    std::cout << "(3) View Wins " << std::endl;
    std::cout << "(4) Exit Game"<< std::endl; 

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
            return "Wins";
        }
        else if (userChoice == 4)
        {
            exit(0);
        }
        else { //If user input is out of bounds of menu options or a string, can catch, clear cin line, and restart loop
            clearBadInput();
            return "badInput";
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
    else //If 1 is not entered clear input
    {
        clearBadInput();
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
        else
        {
            clearBadInput(); //If 1 is not entered clear input
        }
    }

}
