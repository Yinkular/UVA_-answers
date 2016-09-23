//**************************************************************
//                   Project #7 Pole Position
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/08/2016
//***************************************************************
//		The program reads input from a data file containing 
//		two integers per line, the first being the car number
//		and the second an offset from the starting grid, and
//		tries to recreate the starting position from the offset.
//
//		Input format -> Text file, containing a two ints per line
//		Output Format -> an integer (-1) if starting position can't
//						 be recreated or the initial line up.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>


using namespace std;

int main()
{
	// create variables
	int testCase, carNumber, offset, originalPosition;
	bool positionPlausible;

	while (cin >> testCase)
	{
		// condition to stop loop
		if (testCase == 0)
		{
			break;
		}

		//create a vector to store origninal grid positions
		vector<int> gridPosition(testCase, 0);

		positionPlausible = true;

		for (int i = 1; i <= testCase; i++)
		{
			cin >> carNumber >> offset;
			
			originalPosition = (i + offset) - 1;
			
			// check offset is within limits
			if ( originalPosition < 0 || originalPosition >= testCase)
			{
				// set the start position bool to false
				positionPlausible = false;
			}

			else
			{
				// check if the position is not occupied by another competitor
				if (gridPosition[originalPosition] == 0)
				{
					gridPosition[originalPosition] = carNumber;
				}

				else
				{
					positionPlausible = false;
					break;
				}
			}
		}

		// print output based  on positions
		if (positionPlausible)
		{
			int length = gridPosition.size();
			for (int j = 0; j < length; j++)
			{
				cout << gridPosition[j];
				
				if(j < length-1)
				cout << " ";
			}
		}

		else
		{
			cout << "-1";
		}
		cout << endl;
	}
	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________