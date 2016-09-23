//**************************************************************
//                   Project #0 Relational operators
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/06/2016
//***************************************************************
//		The program reads input from a data file containing 
//		specially formatted integers and compares the integers
//		and outputs their rlationship.
//		Input format -> Text file, first line number of data sets
//						subsequent lines, integers to be compared.
//		Output Format -> Relation between integers,greater, lesser
//						 or equal to sign.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>

using namespace std;

int main()
{
	//variable to hold number of data sets
	int dataSets;

	cin >> dataSets;

	//check if there is actually data to be compared
	if (dataSets > 0 && dataSets < 15)
	{
		//variable to store numbers to be compared
		int leftNumber, rightNumber;

		//loop to run through the data sets and compare answers
		for (int i = 1; i <= dataSets; i++)
		{
			//accept both values
			cin >> leftNumber >> rightNumber;

			// compare both sides
			if (leftNumber < rightNumber)
			{
				cout << "<" << endl;
			}

			else if (leftNumber > rightNumber)
			{
				cout << ">" << endl;
			}

			else
			{
				cout << "=" << endl;
			}
		}

	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
// Signature ___________________  