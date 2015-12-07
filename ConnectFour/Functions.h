#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(char grid[6][7])
{
	int i, j;  // Declare the variables for the for loop counters.

	//Display the Welcome Banner.
	printf("\n            Welcome to Connect4!         \n\n\n\n");
	
	//Display the Column Number header.
	printf("   1     2     3     4     5     6     7\n");

	// Display the top corners and top line of the border of the board.
	printf("\xda");
	for (i = 0; i < 41; i++)
	{
		printf("\xc4");
	}
	printf("\xbf");
	printf("\n");
	printf("\xb3%41c\xb3", ' ');

	// Display the sides of the border and column lines of the board.
	for (i = 0; i < 6; i++)
	{
		printf("\n");
		printf("\xb3");

		for (j = 0; j < 7; j++)
		{
			printf("%3c", grid[i][j]);
			if (j < 6)
				printf("  \xb3");
		}
		printf("%2c\xb3", ' ');
		printf("\n");

		// Display the row lines of the board.
		if (i < 5)
			printf("\xb3 \xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4 \xb3");
	}
	printf("\xb3%41c\xb3", ' ');
	printf("\n");

	// Display the bottom corners and bottom line of the border of the board.
	printf("\xc0");
	for (i = 0; i < 41; i++)
	{
		printf("\xc4");
	}
	printf("\xd9");
	printf("\n");
}

int getUI()
{
	int numPlayers;

	// Get user input for number of players.
	while (1)
	{
		printf("Enter the number of players (1 or 2):  ");
		scanf("%d", &numPlayers);

		if (numPlayers != 1 && numPlayers != 2)
			printf("\nInvalid Input.\n\n");
		else
			break;
	}

	return numPlayers;  // Return the number of players to main().
}

void initializeBoard(char arr[][7])
{
	int i, j;

	// Initialize the array(borad) to spaces.
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

int getCol(char player)
{
	int col;
	char temp;
	if (player == 'R')
		temp = '1';  // Temporary variable used to print out which player should enter a column number.  This instance defines player 1.
	else
		temp = '2';  // Temporary variable used to print out which player should enter a column number.  This instance defines player 2.
	while (1)
	{
		// Get user input for the column they want to drop their game piece in.
		printf("\n\nPlayer %c:  Enter in the column number (1 - 7) for the column that you wish to drop your game piece:  ", temp);
		scanf("%d", &col);

		// check for valid input.
		if (col >= 1 && col <= 7)
		{
			break;
		}
		else
		{
			printf("\n\nInvalid Input.\n");
		}
	}
	// Subtract 1 from the column (1 - 7 entered) so that the correct array column (0 - 6) is returned.
	col = col - 1;
	return col;
}

// Make a move for a human player.
int makeMove(char arr[6][7], int col, char player, int *currentMove)
{
	int row = 0;
	int i;

	// Check to see if column entered is valid
	if (col < 0 || col > 6)
	{
		return 0;
	}

	// Check to see column has a spot open
	if (arr[row][col] == ' ')
	{
		for (i = 6; i >= 0; i--)
		{
			if (arr[i][col] == ' ')
			{
				// Keep track of current move for UNDO.
				*currentMove = i;
				// Drop game piece in appropriate column to make move.
				arr[i][col] = player;
				break;
			}
		}
	}
	else
		return -1;

	return 1;
}

int checkWin(char b[6][7])
{
	int i, j;  // Declare variables for the for Loops.
	int retVal = 0;  // Ddfine variable to return to Main().

	// Check rows for a winner.
	for (i = 0; i < 6; i++)
	{
		if (b[i][0] != ' ' && b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][2] == b[i][3])
			retVal = 1;
		else if (b[i][1] != ' ' && b[i][1] == b[i][2] && b[i][2] == b[i][3] && b[i][3] == b[i][4])
			retVal = 1;
		else if (b[i][2] != ' ' && b[i][2] == b[i][3] && b[i][3] == b[i][4] && b[i][4] == b[i][5])
			retVal = 1;
		else if (b[i][3] != ' ' && b[i][3] == b[i][4] && b[i][4] == b[i][5] && b[i][5] == b[i][6])
			retVal = 1;
	}

	// Check columns for a winner.
	for (j = 0; j < 7; j++)
	{
		if (b[0][j] != ' ' && b[0][j] == b[1][j] && b[1][j] == b[2][j] && b[2][j] == b[3][j])
			retVal = 1;
		else if (b[1][j] != ' ' && b[1][j] == b[2][j] && b[2][j] == b[3][j] && b[3][j] == b[4][j])
			retVal = 1;
		else if (b[2][j] != ' ' && b[2][j] == b[3][j] && b[3][j] == b[4][j] && b[4][j] == b[5][j])
			retVal = 1;
	}

	// Check diagonals for a winner.
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (b[i][j] != ' ' && b[i][j] == b[i + 1][j + 1] && b[i + 1][j + 1] == b[i + 2][j + 2] && b[i + 2][j + 2] == b[i + 3][j + 3])
				retVal = 1;
		}
	}
	for (i = 1; i < 4; i++)
	{
		for (j = 6; j > 2; j--)
		{
			if (b[i][j] != ' ' && b[i][j] == b[i + 1][j - 1] && b[i + 1][j - 1] == b[i + 2][j - 2] && b[i + 2][j - 2] == b[i + 3][j - 3])
				retVal = 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (b[i][j] != ' ' && b[i][j] == b[i + 1][j + 1] && b[i + 1][j + 1] == b[i + 2][j + 2] && b[i + 2][j + 2] == b[i + 3][j + 3])
				retVal = 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		for (j = 6; j > 2; j--)
		{
			if (b[i][j] != ' ' && b[i][j] == b[i + 1][j - 1] && b[i + 1][j - 1] == b[i + 2][j - 2] && b[i + 2][j - 2] == b[i + 3][j - 3])
				retVal = 1;
		}
	}
	for (i = 2; i < 6; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (b[i][j] != ' ' && b[i][j] == b[i + 1][j + 1] && b[i + 1][j + 1] == b[i + 2][j + 2] && b[i + 2][j + 2] == b[i + 3][j + 3])
				retVal = 1;
		}
	}
	for (i = 2; i < 6; i++)
	{
		for (j = 6; j > 2; j--)
		{
			if (b[i][j] != ' ' && b[i][j] == b[i + 1][j - 1] && b[i + 1][j - 1] == b[i + 2][j - 2] && b[i + 2][j - 2] == b[i + 3][j - 3])
				retVal = 1;
		}
	}
	return retVal;
}

// Check to see if the board is filled.
int isFilled(char arr[6][7])
{
	int i, j;

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

// Check valid move for the computer player.
int checkValidPCMove(char arr[6][7], int *pcPlayerCol)
{
	int row = 0;

	// Check to see if column has a spot open.
	if (arr[row][*pcPlayerCol] == ' ')
		return 1;
	else
		return 0;
}

// Make move for computer player.
void makePCMove(char arr[6][7], int *pcPlayerCol, int *currentMove, char player)
{
	int i;
	// Loop through possible moves.
	for (i = 5; i >= 0; i--)
	{
		if (arr[i][*pcPlayerCol] == ' ')
		{
			// Keep track of current move for UNDO.
			*currentMove = i;

			// Drop game piece in appropriate column to make move.
			arr[i][*pcPlayerCol] = player;
			break;
		}
	}
}

// Undo last move for a human player.
void undoMove(char arr[6][7], int Col, int Row)
{
	arr[Row][Col] = ' ';
}

char checkValidUndoUI()
{
	char uI;
	while (1)
	{
		// Get user intput for if they want to undo the last move.
		printf("\n\nWould you like to UNDO your last move?  Type \"Y\" for Yes and \"N\" for No.  ");
		scanf(" %c", &uI);  // Space in " %c" to ignore all whitespace and \n.

		// Check to see if user input is valid.
		if (uI != 'Y' && uI != 'y' && uI != 'N' && uI != 'n')
		{
			printf("\n\nInvalid Input.\n");
		}
		else
			break;
	}
	return uI;
}