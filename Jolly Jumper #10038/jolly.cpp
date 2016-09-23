//**************************************************************
//                   Project #2 Jolly Jumper
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/06/2016
//***************************************************************
//		The program reads input from a data file containing 
//		a set of integers per line with the first line 
//		showing the number of data sets. and the program
//		determines if the absolute difference of each element
//		in the dataset is sequential.
//
//		Input format -> Text file, each line contains a data set
//						which are numbers to be worked on.

//		Output Format -> String which says if the set of numbers
//						 are jolly or not.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************


#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	int n;

	// loop till you get to the last line
	while (cin >> n)
	{
		// create needed variables
		vector <int> data(n);
		bool status = true;
		int absoluteDifference, previousAbsolute=0;


		// retrieve each line
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
		}


		//vector to store differences
		vector<int> differences;

		// now compare values
		for (int i = 0; i < n - 1; i++)
		{
			// get the difference between each element
			absoluteDifference = abs(data[i] - data[i + 1]);

			if (absoluteDifference > (n - 1))
			{
				status = false;
				break;
			}
			
			// push the absolute difference to a vector
			differences.push_back(absoluteDifference);
		}

		if (status)
		{
			// sort the vector containing the absolute difference
			sort(differences.begin(), differences.end());
			
			// check through the sorted list and make sure the
			// value is okay
			for (int j = 0; j < differences.size(); j++)
			{
				if (differences[j] != (j + 1))
				{
					status = false;
					break;
				}
			}
		}

		if (status)
		{
			cout << "Jolly" << endl;
		}

		else
		{
			cout << "Not jolly" << endl;
		}

	}
	
	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
// Signature ___________________