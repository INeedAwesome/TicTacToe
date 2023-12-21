/*
* TicTacToe Game
* Created 2023-12-21 by INeedAwesome
*/

#include <iostream>

const int BOARD_SIZE = 9;

void ResetBoard(char spaces[]);
void PrintBoard(char spaces[]);
bool CheckWinner(char spaces[], char player, int& scoreX, int& scoreO);

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
	int playerScoreX = 0;
	int playerScoreO = 0;

	char spaces[BOARD_SIZE] = { 
		'1', '2', '3', 
		'4', '5', '6', 
		'7', '8', '9'
	};
	PrintBoard(spaces);
	ResetBoard(spaces);

	bool continuePlaying = true;
	do {
		int position;
		char character;
		do
		{
			std::cout << "Write a type and position, X or O then 1-9 (e.g. X1): ";
			std::cin >> character >> position;
			if (position == 0)
			{
				return 0;
			}
			ToUpper(character);
		} 
		while (character != 'X' && character != 'O'); // exists when character is X or O

		spaces[position-1] = character;
		
		PrintBoard(spaces);

		continuePlaying = CheckWinner(spaces, character, playerScoreX, playerScoreO);

	} while (continuePlaying);



	return 0;
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

bool CheckWinner(char spaces[], char player, int& playerScoreX, int& playerScoreO)
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

	return true; // continue playing
}

void ToUpper(char& ch)
{
	ch -= 32;
}
