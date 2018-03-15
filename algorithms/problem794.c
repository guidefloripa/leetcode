/*

Author: Guilherme Steinmann
Date: 2018-03-15

A Tic-Tac-Toe board is given as a string array board.
Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:
- Players take turns placing characters into empty squares (" ").
- The first player always places "X" characters, while the second player always places "O" characters.
- "X" and "O" characters are always placed into empty squares, never filled ones.
- The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
- The game also ends if all squares are non-empty.
- No more moves can be played if the game is over.

Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true

Note:
- board is a length-3 array of strings, where each string board[i] has length 3.
- Each board[i][j] is a character in the set {" ", "X", "O"}.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdbool.h>

bool validTicTacToe(char** board, int boardSize) {
	const char X = 'X';
	const char O = 'O';
	
	if (!board || boardSize != 3)
		return false;
	
	int moves = 0;
	for (int i=0; i<boardSize; i++) {
		if (!board[i] || strlen(board[i])<boardSize)
			return false;
		
		for (int j=0; j<boardSize; j++) {
			if (board[i][j] == X)
				moves++;
			else if (board[i][j] == O)
				moves--;
		}
	}
	
	// check if 'X' is first, 'O' is second, and so on...
	if (moves != 0 && moves != 1)
		return false;
	
	int winsX = 0;
	int winsO = 0;
	for (int i=0; i<boardSize; i++) {
		// count row wins
		if (board[i][0] == X && board[i][1] == X && board[i][2] == X)
			winsX++;
		else if (board[i][0] == O && board[i][1] == O && board[i][2] == O)
			winsO++;
		
		// count column wins
		if (board[0][i] == X && board[1][i] == X && board[2][i] == X)
			winsX++;
		else if (board[0][i] == O && board[1][i] == O && board[2][i] == O)
			winsO++;
	}
	
	// count diagonal wins
	if (board[0][0] == X && board[1][1] == X && board[2][2] == X)
		winsX++;
	else if (board[0][0] == O && board[1][1] == O && board[2][2] == O)
		winsO++;
	
	if (board[0][2] == X && board[1][1] == X && board[2][0] == X)
		winsX++;
	else if (board[0][2] == O && board[1][1] == O && board[2][0] == O)
		winsO++;
	
	// check if both win
	if (winsX>0 && winsO>0)
		return false;
	
	// check if end on 'O' and 'X' win
	if (moves==0 && winsX>0)
		return false;
	
	// check if end on 'X' and 'O' win
	if (moves==1 && winsO>0)
		return false;
	
	return true;
}

int main(int argc,char *argv[])
{
	char* board[3] = { "XXX","OOX","OOX" };

	bool b = validTicTacToe(board, 3);

	printf("%s\n", b ? "TRUE" : "FALSE");
	return 0;
}
