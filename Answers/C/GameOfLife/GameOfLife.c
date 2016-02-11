#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "MyColorChanger.h"

/*Game settings*/
#define LIVE_CELL 254
#define DEAD_CELL 32
#define BOARD_SIZE 15
#define NUMBER_OF_ROUNDS 1000

/*Return values*/
#define SUCCESS 0
#define ERROR -1

/*Patterns*/
void rPentomino(unsigned char board[][BOARD_SIZE]);
void blinkerOscillator(unsigned char board[][BOARD_SIZE]);
void pulsarOscillator(unsigned char board[][BOARD_SIZE]);
void pentadecathlonOscillator(unsigned char board[][BOARD_SIZE]);

/*Functions*/
int initializeWorld(unsigned char board[][BOARD_SIZE]);
int countLivesNeighbors(unsigned char board[][BOARD_SIZE], unsigned int row, unsigned int col);
void round(unsigned char board[][BOARD_SIZE]);
void printWorld(unsigned char board[][BOARD_SIZE]);
void printBorders();


int main()
{
	unsigned char board[BOARD_SIZE][BOARD_SIZE] = {DEAD_CELL};
	int i, j;

	/* initialize the board game.*/
	if ( initializeWorld(board) == -1 )
	{
		system("pause");
		return ERROR;
	}

	/* print the board and wait more 2 seconds. */
	printWorld(board);
	Sleep(2000);

	/*The game rounds.*/
	for ( i = 0 ; i < NUMBER_OF_ROUNDS ; i++ )
	{
		round(board);
		printWorld(board);
	}

	system("pause");
	return SUCCESS;
}


/*
	Initialize the board game by the chosen pattern.
*/
int initializeWorld(unsigned char board[][BOARD_SIZE])
{
	unsigned int choice = 0;
	
	printf("Choose which oscillator do you want to initialize:\n\n"
		   "1.The blinker:\n\n O O O\n\n"
		   "2.The rPentomino:\n\n   O O\n O O\n   O\n\n"
		   "3.The pulsar:\n\n   O\n O O O\n O   O\n O O O\n   O\n\n"
		   "4.The pentadecathlon:\n\n O O O O O O O O O O\n\n"
		   "Your choice: ");

	scanf("%d", &choice);

	switch ( choice )
	{
		case 1:
			blinkerOscillator(board);
			break;

		case 2:
			rPentomino(board);
			break;

		case 3:
			pulsarOscillator(board);
			break;

		case 4:
			pentadecathlonOscillator(board);
			break;

		default:
			printf("Not supported choice, please choose again!\n");
			return ERROR;
	}
	
	return SUCCESS;
}


/* 
		O O
	  O O
		O
*/
void rPentomino(unsigned char board[][BOARD_SIZE])
{


	int i, j;

	for ( i = 0 ; i < BOARD_SIZE ; i++ )
	{
		for ( j = 0 ; j < BOARD_SIZE ; j++)
		{
			board[i][j] = DEAD_CELL;
		}
	}

	board[BOARD_SIZE / 2 - 1][BOARD_SIZE/2] = LIVE_CELL;
	board[BOARD_SIZE / 2 - 1][BOARD_SIZE/2 + 1] = LIVE_CELL;

	board[BOARD_SIZE / 2][BOARD_SIZE/2] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE/2 - 1] = LIVE_CELL;

	board[BOARD_SIZE / 2 + 1][BOARD_SIZE/2] = LIVE_CELL;
}


/*
	O O O
*/
void blinkerOscillator(unsigned char board[][BOARD_SIZE])
{
	/*
		O O O
	*/
	int i, j;

	for (i = 0; i < BOARD_SIZE; ++i)
	{
		for (j = 0; j < BOARD_SIZE; ++j)
		{
			board[i][j] = DEAD_CELL;
		}
	}

	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 + 1] = LIVE_CELL;

}


/*
	  O
	O O O
	O   O
	O O O
	  O
*/
void pulsarOscillator(unsigned char board[][BOARD_SIZE])
{
	int i, j;

	for (i = 0; i < BOARD_SIZE; ++i)
	{
		for (j = 0; j < BOARD_SIZE; ++j)
		{
			board[i][j] = DEAD_CELL;
		}
	}

	board[BOARD_SIZE / 2 + 2][BOARD_SIZE / 2] = LIVE_CELL;

	board[BOARD_SIZE / 2 + 1][BOARD_SIZE / 2 - 1] = LIVE_CELL;
	board[BOARD_SIZE / 2 + 1][BOARD_SIZE / 2] = LIVE_CELL;
	board[BOARD_SIZE / 2 + 1][BOARD_SIZE / 2 + 1] = LIVE_CELL;

	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 + 1] = LIVE_CELL;

	board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = LIVE_CELL;
	board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2] = LIVE_CELL;
	board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 + 1] = LIVE_CELL;

	board[BOARD_SIZE / 2 - 2][BOARD_SIZE / 2] = LIVE_CELL;
}


/*
	O O O O O O O O O O 
*/
void pentadecathlonOscillator(unsigned char board[][BOARD_SIZE])
{
	int i, j;
	if ( BOARD_SIZE < 10 )
	{
		printf("Board size smaller than 10, pentadecathlon can't be initialized!\n");
		system("pause");
		exit(-1);
	}

	for (i = 0; i < BOARD_SIZE; ++i)
	{
		for (j = 0; j < BOARD_SIZE; ++j)
		{
			board[i][j] = DEAD_CELL;
		}
	}

	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 5] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 4] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 3] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 2] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] =	LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 0] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 + 1] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 + 2] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 + 3] = LIVE_CELL;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 + 4] = LIVE_CELL;

}

/*
	This function is responsible for each round.
	It's count the live neighbors of each cell on the board and considered by the rules which changes to do.
*/
void round(unsigned char board[][BOARD_SIZE])
{
	unsigned char newBoard[BOARD_SIZE][BOARD_SIZE];
	int liveNeighbors = 0;
	int i, j;
	
	for ( i = 0 ; i < BOARD_SIZE ; i++ )
	{
		for ( j = 0 ; j < BOARD_SIZE ; j++ )
		{
			/*Count the live neighbors of each cell*/
			liveNeighbors = countLivesNeighbors(board, i, j);

			/*Play By The Rules*/

			/*Birth*/
			if ( board[i][j] == DEAD_CELL && liveNeighbors == 3 )
				newBoard[i][j] = LIVE_CELL;

			/*Survival*/
			else if ( board[i][j] == LIVE_CELL && ( liveNeighbors == 2 || liveNeighbors == 3 ) )
				newBoard[i][j] = LIVE_CELL;

			/*Overcrowding or Loneliness*/
			else
				newBoard[i][j] = DEAD_CELL;
		
		}
	}

	/*Copy the next round board to the current round board (Copy the new board to the game board).*/
	for ( i = 0 ; i < BOARD_SIZE ; i++ )
	{
		for ( j = 0 ; j < BOARD_SIZE ; j++ )
		{
			board[i][j] = newBoard[i][j];
		}
	}
}


/*
	Print the game board.
*/
void printWorld(unsigned char board[][BOARD_SIZE])
{
	int i, j;
	system("cls");
	for ( i = 0 ; i < BOARD_SIZE ; i++ )
	{
		printBorders();
		for ( j = 0 ; j < BOARD_SIZE ; j++)
		{
			if ( board[i][j] == LIVE_CELL )
			{
				printf("|");
				greenText();
				printf(" %c ", board[i][j]);
			}
			else
			{
				printf("| %c ", board[i][j]);
			}
			whiteText();
		}
		printf("|\n");
	}
	printBorders();
	Sleep(1000);
}


/*
		Print the borders of the game board.
	*/
void printBorders()
{
	int borderSize = 4 * BOARD_SIZE; /* Calculat the lengh of the board for print the '=' charachter. */
	int countBorderPrint = 0;
	while ( countBorderPrint < borderSize )
	{
				printf("="); 
				countBorderPrint++;
	}
	countBorderPrint = 0;
	printf("=\n"); /* I Calculated the lengh of the board and I had to multiple the board size with 4 point something, so I add one '=' to fix the variation. */
}


/*
	Return the number of live neighbors of spcified cell.
*/
int countLivesNeighbors(unsigned char board[][BOARD_SIZE], unsigned int row, unsigned int col)
{
	int numberOfLiveNeighbors = 0 ;
	int i, j;

	/* If row / col is 0, so I dont need to check the -1 row or col.
		therefore, I have to check it and choose if i/j is row/col or ( row/col - 1 ) */
	for ( i = ( row == 0 ? row : row - 1 ) ; i <= (row + 1) && i <= BOARD_SIZE ; i++ ) 
	{
		for ( j = ( col == 0 ? col : col - 1 ) ; j <= (col + 1) && j <= BOARD_SIZE ; j++ )
		{
			if ( ( board[i][j] == LIVE_CELL ) && !( i == row && j == col ) )
			{
				numberOfLiveNeighbors++;
			}
		}
	}

	return numberOfLiveNeighbors;
}

