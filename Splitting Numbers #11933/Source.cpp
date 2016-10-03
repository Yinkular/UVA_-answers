//**************************************************************
//                   Project : #13 Splitting Numbers 
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 10/03/2016
//***************************************************************
//		Program tries to split an integer based on bits turned on
//		into two different integers, one representing the even bits
//		turned on and the other odd bits.
//
//      Input format -> Text file, containing integers to be changed
//						from a single integer to two halves
//
//      Output Format -> integers represnting halves.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>

#define endl "\n";

using namespace std;

int main()
{
	int number;

	while (cin >> number && number != 0)
	{
		//cout << number << endl;

		// variables
		// a, b for output
		// mask is for the masked bit
		// t for result of and test
		// count is to get the number of ones currently encountered
		int a, b, mask,t, count =0;
		a = b = 0;

		// set mask to first bit
		mask = 1;

		// run through the whole bits
		for (int i = 1; i <= 32; i++)
		{
			// test if the current bit is a 1 or 0
			t =  number & mask;

			// if t is not a zero
			if (t != 0)
			{
				count++;

				// if the 1 is even
				if (count % 2 == 0)
				{
					b = b | mask;
				}

				//else if it is odd
				else
				{
					a = a | mask;
				}
			}

			// move the mask to the next bit 
			mask = mask << 1;
		}

		cout << a << " " << b << endl;
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________