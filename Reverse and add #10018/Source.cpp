//**************************************************************
//                   Project: #10 Reverse and Add
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/13/2016
//***************************************************************
//		The program contains set of integers,reverse its digits and 
//		add it to the original.If the sum is not a palindrome , 
//		repeat this procedure
//
//      Input format -> Text file, contains sets of integers
//      Output Format -> The number of iterations it takes to 
//						 get the palindrome
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int reverse(int number)
{
	int newNumber=0;

	while (number > 0)
	{
		newNumber = (newNumber * 10) + (number % 10);
		number = number / 10;
	}
	
	return newNumber;
}

int main()
{
	// create variables
	unsigned int testCases, originalNumber, reversedNumber, sum, iterations, reversedSum;

	cin >> testCases;


	// loop through test cases
	for (int i = 1; i <= testCases; i++)
	{
		// initialize iteration to zero
		iterations = 0;

		// get original number
		cin >> originalNumber;

		while (true)
		{
			iterations++;

			//reverse  the number
			reversedNumber = reverse(originalNumber);

			// get the sum
			sum = reversedNumber + originalNumber;

			// get the reverse of the sum
			reversedSum = reverse(sum);

			// if we reach our answer
			if (sum == reversedSum)
			{
				break;
			}

			else
			{
				// set our sum as the new original number
				originalNumber = sum;
			}
		}

		cout << iterations << " " << sum << endl;
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________