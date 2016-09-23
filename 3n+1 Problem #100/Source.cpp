//**************************************************************
//                   Project Extra Credit (Alaska)
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/23/2016
//***************************************************************
//      The program tries the cycle length between two numbers
//		incusive and output it to screen
//
//      Input format -> Text file, containing two integers per line
//		in no speciic order.
//      Output Format -> The two numbers followed by the cyle length
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
	// create variables
	int first, second, start, stop, maxCycle, currentNumber, cyclesCount;

	// accept input and loop through the data set
	while (cin >> first >> second)
	{
		// initialize to zero at beginning of each loop
		maxCycle = 0;

		// set max to stop and minimum to start
		start = min(first, second);
		stop = max(first, second);

		// loop through the start and stop points
		for (int i = start; i <= stop; i++)
		{
			// get the current number to be worked on
			currentNumber = i;

			// initialize cycles to zero per loop
			cyclesCount = 1;

			// get number of cycles
			while (currentNumber != 1)
			{
				if (currentNumber % 2 == 0)
				{
					currentNumber = currentNumber / 2;
				}

				else
				{
					currentNumber = (3 * currentNumber) + 1;
				}

				// increase the cycle count at the end of each loop
				cyclesCount++;
			}

			// get the current maxCycle
			if (cyclesCount > maxCycle)
			{
				maxCycle = cyclesCount;
			}
		}

		// print out answer for current data set
		cout << first << " " << second << " " << maxCycle << endl;
	}
	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________