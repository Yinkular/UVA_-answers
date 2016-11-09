//**************************************************************
//                   Project: #15 Ones
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 10/20/2016
//***************************************************************
//   	Program prints out the number of ones in an integer. 
//
//      Input format -> A file of integers at one integer per line
//      Output Format -> Number of digits in its multiple of ones
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{
	unsigned long number, answer, power, count;

	while (cin >> number)
	{
		int count = 1, digit = 1;

		while (digit %number != 0 && ++count)
		{
			digit = (digit * 10) + 1;
		}

		cout << count << endl;
	}

	return 0;
}
// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________