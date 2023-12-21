/*
* TicTacToe Game
* Created 2023-12-21 by INeedAwesome
*/

#include <iostream>

const int BOARD_SIZE = 9;

void ResetBoard(char spaces[]);
void PrintBoard(char spaces[]);

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
	char spaces[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	PrintBoard(spaces);
	ResetBoard(spaces);

	do {
		int position;
		char character;
		do
		{
			std::cout << "Write a position, 1-9 and X or O (e.g. 1X): ";
			std::cin >> position >> character;
			if (position == 0)
			{
				return 0;
			}
			ToUpper(character);
		} 
		while (character != 'X' && character != 'O'); // exists when character is X or O

		spaces[position-1] = character;
		
		PrintBoard(spaces);

	} while (true);



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

void ToUpper(char& ch)
{
	ch -= 32;
}