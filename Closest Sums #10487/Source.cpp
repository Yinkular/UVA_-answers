//**************************************************************
//                   Project : Closests Sums (Extra Credit)
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 10/03/2016
//***************************************************************
//		Given is a set of integers and then a sequence of queries. 
//		A query gives you a number and asks to find a sum of two 
//		distinct numbers from the set, which is closest to the query number.
//
//      Input format -> Each case starts with an integer n (1 < n <= 1000), 
//		which indicates, how many numbers are in the set of integer. Next
//		 n lines contain n numbers. Of course there is only one number in a 
//		single line. The next line contains a positive integer m giving the 
//		number of queries, 0 < m < 25. The next m lines contain an integer of the query,
//		one per line.
//
//      Output Format -> single integer per line showing closest sums.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl "\n";

using namespace std;

int main()
{
	// variable for number of test cases
	int setSize, querySize, currentCase = 0;

	// loop till set size is 0
	while (cin >> setSize && setSize != 0)
	{
		currentCase++;

		// create a vector using the setsize
		vector<int> elements(setSize);

		// accept values into the vector
		for (int i = 0; i < setSize; i++)
		{
			cin >> elements[i];
		}

		// create a vector sum
		vector<int> sum;

		// loop to get the sum of distinct values
		for (int i = 0; i < setSize; i++)
		{
			for (int j = 0; j < setSize; j++)
			{
				if (i != j)
				{
					sum.push_back(elements[i] + elements[j]);
				}
			}
		}

		// sort the sum
		sort(sum.begin(), sum.end());

		// get the queries
		cin >> querySize;

		cout << "Case " << currentCase << ":" << endl;

		// loop through queries
		for (int i = 1; i <= querySize; i++)
		{
			int answer, queryValue, difference = 0, currentDifference;

			cin >> queryValue;

			//loop through sum for answer
			for (int j = 0; j < sum.size(); j++)
			{
				currentDifference = abs(sum[j] - queryValue);

				//  if values are equal
				if (currentDifference == 0)
				{
					answer = sum[j];
					break;
				}

				else
				{
					// if we are just starting
					if (difference == 0)
					{
						difference = currentDifference;
						answer = sum[j];
					}

					// if the current difference is smaller than the previous smallest
					else if (currentDifference < difference)
					{
						difference = currentDifference;
						answer = sum[j];
					}
				}
			}
			
			cout << "Closest sum to " << queryValue << " is " << answer << "."<< endl;
		}
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________