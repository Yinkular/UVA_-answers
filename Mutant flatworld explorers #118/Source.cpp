//**************************************************************
//                   Project: #18 Mutant Flatworld Explorers
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 10/27/2016
//***************************************************************
//   	Program navigates a robot through a grid and tells if they
//		fall off the grid or not.
//		
//		Input->  File containing grid size, initial position of the
//				 robot and directions to navigate.
//		Output -> A line showing final position of the Robot or the 
//					the position before falling off if it does.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int row, column, startX, startY;
	char startCoor;

	cin >> row >> column;

	// create a grid of row and column
	bool grid[50][50] = {false};


	while (cin >> startX >> startY >> startCoor)
	{
		string instructions;
		cin >> instructions;

		bool lost = false;

		char currentInstruction;

		for (int i = 0; i < instructions.length(); i++) // loop for length of instruction
		{
			currentInstruction = instructions[i];

			if (currentInstruction == 'F') // where movement actually takes place
			{
				if (startCoor == 'N')
				{
					startY++; // go up by one
				}

				else if (startCoor == 'E')
				{
					startX++; // go right by one
				}

				else if (startCoor == 'S')
				{
					startY--; // go down by one
				}

				else if (startCoor == 'W')
				{
					startX--; // go left by one
				}
				
			}

			else if (currentInstruction == 'R') // right just changes cartesian coordinate by 90 right
			{
				if (startCoor == 'N')
				{
					startCoor = 'E';
				}

				else if (startCoor == 'E')
				{
					startCoor = 'S';
				}

				else if (startCoor == 'S')
				{
					startCoor = 'W';
				}

				else if (startCoor == 'W')
				{
					startCoor = 'N';
				}
			}

			else if (currentInstruction == 'L') // left just changes cartesian coordinate by 90 left
			{
				if (startCoor == 'N')
				{
					startCoor = 'W';
				}

				else if (startCoor == 'W')
				{
					startCoor = 'S';
				}

				else if (startCoor == 'S')
				{
					startCoor = 'E';
				}

				else if (startCoor == 'E')
				{
					startCoor = 'N';
				}
			}

			// check if you are not out of bounds
			if (startX < 0 || startX > row || startY < 0 || startY > column)
			{
				// if true, the last position before going out should be gotten
				if (startCoor == 'N')
				{
					startY--;
				}

				else if (startCoor == 'E')
				{
					startX--;
				}

				else if (startCoor == 'S')
				{
					startY++;
				}

				else if (startCoor == 'W')
				{
					startX++;
				}

				// check if any robot has fallen off that position 
				if (!grid[startX][startY])
				{
					lost = true;
					grid[startX][startY] = true;
					break;
				}
			}
		}

		if (lost) // if robot falls off grid
		{
			cout << startX << " " << startY << " " << startCoor << " LOST" << endl;
		}

		else
		{
			cout << startX << " " << startY << " " << startCoor << endl;
		}
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________