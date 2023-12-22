/*
* Tic-Tac-Toe Game
* Created 2023-12-21 by INeedAwesome
*/

#include <iostream>

const int BOARD_SIZE = 9;

bool MakeMove(char spaces[], char& character, int& position);
void ResetBoard(char spaces[]);
void PrintBoard(char spaces[]);
bool CheckWinner(char spaces[], char player, int& scoreX, int& scoreO, int& moves);

void ToUpper(char& ch);

int main()
{	
	/*
	* -------------
	* | X | X | X |
	* | X | X | X |
	* | X | X | X |
	* -------------
	*/
	int playAgain = 0;
	int moves = 0;
	int playerScoreX = 0;
	int playerScoreO = 0;

	do
	{
		moves = 0;
		char spaces[BOARD_SIZE] = { 
			'1', '2', '3', 
			'4', '5', '6', 
			'7', '8', '9'
		};
		PrintBoard(spaces);
		ResetBoard(spaces);

		bool continuePlaying = true;
		do {
			int position = 0;
			char character = ' ';

			if (MakeMove(spaces, character, position) == false) 
				return 0;

			PrintBoard(spaces);

			continuePlaying = CheckWinner(spaces, character, playerScoreX, playerScoreO, moves);
		}
		while (continuePlaying);
		std::cout << "Play Again?\n0. No \n1. Yes" << std::endl;
		std::cin >> playAgain;
		system("cls");

	} 
	while (playAgain);

	return 0;
}

bool MakeMove(char spaces[], char& character, int& position)
{
	while (character != 'X' && character != 'O') // exits when character is X or O
	{
		std::cout << "Write a type and position, X/O, 1-9 (e.g. x1): ";
		std::cin >> character >> position;
		if (position == 0)
		{
			std::cout << " - Incorrect format! X/O, 1-9 (e.g. x1): ";
			return false;
		}
		ToUpper(character);

		if (spaces[position - 1] == ' ')
		{
			spaces[position - 1] = character;
		}
	}
	return true;
}

void ResetBoard(char spaces[])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		spaces[i] = ' ';
	}
}

void PrintBoard(char spaces[])
{
	std::cout << "-------------" << std::endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		// Write the | in the beginning of the line
		if (i % 3 == 0)
		{
			std::cout << "|";
		}
		// Write the value of the space
		std::cout << " " << spaces[i] << " |";
		// New line if its writing out index 2 or 5
		if (i % 3 == 2)
		{
			std::cout << std::endl;
		}
	}
	std::cout << "-------------" << std::endl;
}

bool CheckWinner(char spaces[], char player, int& playerScoreX, int& playerScoreO, int& moves)
{
	// check row
	for (int i = 0; i < BOARD_SIZE; i+=3)
	{
		if (spaces[i] == player && spaces[i+1] == player && spaces[i+2] == player)
		{
			std::cout << std::endl << player << " Won the game!" << std::endl;
			return false; 
		}
	}

	// check column
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (spaces[i] == player && spaces[i + (1 * 3)] == player && spaces[i + (2 * 3)] == player)
		{
			std::cout << std::endl << player << " Won the game!" << std::endl;
			return false;
		}
	}

	// check left to right diagonal
	if (spaces[0] == player && spaces[4] == player && spaces[8] == player)
	{
		std::cout << std::endl << player << " Won the game!" << std::endl;
		return false;
	}

	// check right to left diagonal
	if (spaces[2] == player && spaces[4] == player && spaces[6] == player)
	{
		std::cout << std::endl << player << " Won the game!" << std::endl;
		return false;
	}

	if (moves >= 8)
	{
		std::cout << "Draw!" << std::endl;
		return false;
	}
	moves++;

	return true; // continue playing
}

void ToUpper(char& ch)
{
	ch -= 32;
}
