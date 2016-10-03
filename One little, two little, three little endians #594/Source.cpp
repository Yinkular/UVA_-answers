//**************************************************************
//  Project : #14 One Little, Two Little, Three Little Endians 
//							(USING BITSETS)
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 10/03/2016
//***************************************************************
// 		Program converts a 32 bit integer from an endian form to another
//
//      Input format -> Text file, containing integers to be changed
//						from one endian form to another
//
//      Output Format -> original number and endian transformation.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// variable to store input
	int number;

	//loop till end of file
	while (cin >> number)
	{
		// initalize a bitset contructor for number of size 32 bits
		bitset<32> bits(number);
		bool temp;

		int setNo=0, sets=3, iterator=0;

		// loop through bit set and replace positions
		for (int i = 0; i < 16;i++)
		{
			temp = bits[i];
			bits[i] = bits[(sets * 8) + iterator];
			bits[(sets * 8) + iterator] = temp;

			iterator++;

			if ((i + 1) % 8 == 0)
			{
				iterator = 0;
				sets--;
			}

		}

		cout << number << " converts to " <<(int) bits.to_ulong() << endl;
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________