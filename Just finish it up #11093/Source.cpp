//**************************************************************
//                   Project Extra Credit
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/13/2016
//***************************************************************
//      The program reads input from a file, this input are sets
//		of integers and computes a point at which a racer can start
//		the race and get to the finish point
//
//      Input format -> Text file,  each line contains set of integers
//      Output Format -> A string that shows if the race can be comple-
//						 ted or not
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
	int noOfTestCases, vectorSize, sumAvailable, sumNeeded, startPoint=0;
	bool possible;

	cin >> noOfTestCases;

	for (int j = 1; j <= noOfTestCases; j++)
	{
		// retrive vector size
		cin >> vectorSize;

		// create vector variables for petrol available and qunatity
		vector <int> petrolAvailable(vectorSize);
		vector <int> quantityNeeded(vectorSize);

		// initialize sum available and needed to 0
		sumAvailable = sumNeeded = 0;

		// swt possible to true
		possible = true;

		//accept input for each vector
		// accept for petrol available
		for (int i = 0; i < vectorSize; i++)
		{
			cin >> petrolAvailable[i];

			//get the sum 
			sumAvailable += petrolAvailable[i];
		}

		// accept for quantity needed
		for (int i = 0; i < vectorSize; i++)
		{
			cin >> quantityNeeded[i];

			//get the sum
			sumNeeded += quantityNeeded[i];
		}

		// check for first condition
		if (sumAvailable < sumNeeded)
		{
			possible = false;
		}

		else
		{
			int available = 0, needed = 0,previousneeded=0,previousAvailable=0;

			//loop through the circular track
			for (int i = 0; i < vectorSize; i++)
			{
				available += petrolAvailable[i];
				needed += quantityNeeded[i];
				
				if (available < needed)
				{
					previousneeded += needed;
					previousAvailable += available;

					needed = 0;
					available = 0;

					startPoint = 0;
				}

				else if (available >= needed && startPoint == 0)
				{
					startPoint = i + 1;
				}
			}

			if (startPoint == 0)
			{
				possible = false;
			}

		}

		if (possible)
		{
			cout << "Case " << j << ": Possible from station " << startPoint;
		}

		else
		{
			cout <<"Case " << j << ": Not possible";
		}

		cout << endl;
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________