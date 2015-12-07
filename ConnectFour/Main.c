#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"

int main(void)
{
	// Declare variables.
	char board[6][7];  // Create Connect 4 game board array.
	int numPlayers;  // Declare variable to store whether there will be 1 or 2 human players.
	char player1 = 'R';  // Set human player 1's game piece to "R", or red.
	char player2 = 'B';  // Set human player 2's game piece to "B", or black.
	char pcPlayer = 'B';  // Set Computer player's game piece to "B", or black.
	int player1Col;  // Declare variable to store which column human player 1 chooses to drop the game piece in.
	int player2Col;  // Declare variable to store which column human player 2 chooses to drop the game piece in.
	int pcPlayerCol;  // Declare variable to store which column the computer chooses to drop the game piece in.
	int checkValidMove;  // Declare a variable for which to call the makeMove() function from that will check move validity before making a move to store the appropriate return value.
	char undoMoveInput;  //Declare a variable to store user input for UNDO last move.
	int currentMoveRow;  // Declare variable to store the player's row of the current move to use in the UNDO function to undo move.
	int pcMoveRow;  // Declare a variable to store the computer player's row for the current move to use in the UNDO function to undo move for AI.
	char win;  // Declare a variable to store the computer player's move status for win for AI.
	char block;  // Declare a variable to store the computer player's move status for block for AI.

	// Set seed for randomization for the computer moves.
	srand((unsigned int)time(NULL));

	// Initialize the board to spaces.
	initializeBoard(board);

	// Display welcome banner.
	printf("\n\tWELCOME TO CONNECT 4!\n\n\n\n");

	// Get user input for number of players.
	numPlayers = getUI();

	// Display the number of players.
	printf("\nNumber of players is:  %d\n\n", numPlayers);

	// Display the blank board.
	display(board);

	// Play a Player vs Player (2 Player) game.
	while (1)
	{
		if (numPlayers == 2)
		{
			// Player 1
			while (1)
			{
				// Get user input for the column they want to drop their game piece in.
				player1Col = getCol(player1);

				// Print a blank line for readability.
				puts("");

				// Make Player 1's move.
				checkValidMove = makeMove(board, player1Col, player1, &currentMoveRow);
				if (checkValidMove == 1)
				{
					// Display the board.
					display(board);

					// Undo last move if user chooses to do so.
					undoMoveInput = checkValidUndoUI();

					if (undoMoveInput == 'Y' || undoMoveInput == 'y')
					{
						undoMove(board, player1Col, currentMoveRow);

						// Display the board.
						printf("\n\n");  // Print blank lines for readability.
						display(board);
						continue;
					}
					else
					{
						// Display the board.
						printf("\n\n");  // Print blank lines for readability.
						display(board);
						break;
					}
				}
				// Invalid column entered.
				else if (checkValidMove == 0)
					printf("\nInvalid column entered.\n\n");
				// Spot on board already has a game piece.
				else
					// Add 1 to player1Col so that the correct column is displayed on the screen, ie 1 instead of 0.  Game borad starts with column 1.
					printf("\nColumn is full.  Cannot drop a game piece in column %d.\n\n", player1Col + 1);
			}

			// Check to see if Player 1 won.
			if (checkWin(board))
			{
				printf("\nPLAYER 1 WINS!\n\n");
				break;
			}

			// Check for a full board --- tie/draw game.
			if (isFilled(board))
			{
				printf("No one wins.  Game is a draw!\n\n");
				break;
			}

			// END PLAYER1.

			// Player 2
			while (1)
			{
				// Get user input for the column they want to drop their game piece in.
				player2Col = getCol(player2);

				// Print a blank line for readability.
				puts("");

				// Make Player 2's move.
				checkValidMove = makeMove(board, player2Col, player2, &currentMoveRow);
				if (checkValidMove == 1)
				{
					// Display the board.
					display(board);

					// Undo last move if user chooses to do so.
					undoMoveInput = checkValidUndoUI();

					if (undoMoveInput == 'Y' || undoMoveInput == 'y')
					{
						undoMove(board, player2Col, currentMoveRow);

						// Display the board.
						printf("\n\n");  // Print blank lines for readability.
						display(board);
						continue;
					}
					else
					{
						// Display the board.
						printf("\n\n");  // Print blank lines for readability.
						display(board);
						break;
					}
				}
				// Invalid column entered.
				else if (checkValidMove == 0)
					printf("\nInvalid column entered.\n\n");
				// Spot on board already has a game piece.
				else
					// Add 1 to player2Col so that the correct column is displayed on the screen, ie 1 instead of 0.  Game borad starts with column 1.
					printf("\nColumn is full.  Cannot drop a game piece in column %d.\n\n", player2Col + 1);
			}

			// Check to see if Player 2 won.
			if (checkWin(board))
			{
				printf("\nPLAYER 2 WINS!\n\n");
				break;
			}

			// Check for a full board --- tie/draw game.
			if (isFilled(board))
			{
				printf("\nNO ONE WINS.  GAME IS A DRAW!\n\n");
				break;
			}

			// END PLAYER2.
		}

		// Play a Player vs Computer (1 Player) game.
		else
		{
			// Player 1
			while (1)
			{
				// Get user input for the column they want to drop their game piece in.
				player1Col = getCol(player1);

				// Print a blank line for readability.
				puts("");

				// Make Player 1's move.
				checkValidMove = makeMove(board, player1Col, player1, &currentMoveRow);
				if (checkValidMove == 1)
				{
					// Display the board.
					display(board);

					// Undo last move if user chooses to do so.
					undoMoveInput = checkValidUndoUI();

					if (undoMoveInput == 'Y' || undoMoveInput == 'y')
					{
						undoMove(board, player1Col, currentMoveRow);

						// Display the board.
						printf("\n\n");  // Print blank lines for readability.
						display(board);
						continue;
					}
					else
					{
						// Display the board.
						printf("\n\n");  // Print blank lines for readability.
						display(board);
						break;
					}
				}
				// Invalid column entered.
				else if (checkValidMove == 0)
					printf("\nInvalid column entered.\n\n");
				// Spot on board already has a game piece.
				else
					// Add 1 to player1Col so that the correct column is displayed on the screen, ie 1 instead of 0.  Game borad starts with column 1.
					printf("\nColumn is full.  Cannot drop a game piece in column %d.\n\n", player1Col + 1);
			}

			// Check to see if Player 1 won.
			if (checkWin(board))
			{
				printf("\nPLAYER 1 WINS!\n\n");
				break;
			}

			// Check for a full board --- tie/draw game.
			if (isFilled(board))
			{
				printf("No one wins.  Game is a draw!\n\n");
				break;
			}

			// END PLAYER1.

			// Computer Player
			while (1)
			{
				// Play winning move if wining move exists.
				for (pcPlayerCol = 0; pcPlayerCol < 7; pcPlayerCol++)
				{
					if (checkValidPCMove(board, &pcPlayerCol))
					{
						makePCMove(board, &pcPlayerCol, &pcMoveRow, pcPlayer);

						if (checkWin(board))
						{
							win = 'Y';
							printf("\nComputer drops winning game piece in column:  %d!\n\n", pcPlayerCol + 1);
							// Display the board.
							display(board);
							break;
						}
						else
						{
							win = 'N';
							undoMove(board, pcPlayerCol, pcMoveRow);
						}
					}
				}

				// Play blocking move if blocking move exists.
				if (win == 'N')
				{
					for (pcPlayerCol = 0; pcPlayerCol < 7; pcPlayerCol++)
					{
						if (checkValidPCMove(board, &pcPlayerCol))
						{
							// Make a move with Player 1's game piece to check if Player 1 can win.
							makePCMove(board, &pcPlayerCol, &pcMoveRow, player1);

							if (checkWin(board))
							{
								block = 'Y';
								// Undo move with Player 1's game piece so Computer Player can make the blocking move.
								undoMove(board, pcPlayerCol, pcMoveRow);
								// Make the blocking move.
								makePCMove(board, &pcPlayerCol, &pcMoveRow, pcPlayer);
								printf("\nComputer drops win blocking game piece in column:  %d!\n\n", pcPlayerCol + 1);
								// Display the board.
								display(board);
								break;
							}
							else
							{
								block = 'N';
								undoMove(board, pcPlayerCol, pcMoveRow);
							}
						}
					}
				}

				// Play random move for computer if now winning or blocking moves exist.
				if (win == 'N' && block == 'N')
				{
					pcPlayerCol = (rand() % 7);  // Randomly choose a column for which the Computer Player will "drop" its game piece.

					// Make Computer Player's move.
					if (checkValidPCMove(board, &pcPlayerCol))
					{
						makePCMove(board, &pcPlayerCol, &pcMoveRow, pcPlayer);
						printf("\nComputer drops game piece in column:  %d\n\n", pcPlayerCol + 1);
						// Display the board.
						display(board);
						break;
					}
				}
				else
					break;
			}

			// Check to see Computer Player won.
			if (checkWin(board))
			{
				printf("\nComputer WINS!\n\n");
				break;
			}

			// Check for a full board --- tie/draw game.
			if (isFilled(board))
			{
				printf("\nNO ONE WINS.  GAME IS A DRAW!\n\n");
				break;
			}

			// END Computer Player.
		}
	}

	return 0;
}