#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// little preprocessing
	string first, second, third, fourth, fifth, sixth;

	first = "BFPV";
	second = "CGJKQSXV";
	third = "DT";
	fourth = "L";
	fifth = "MN";
	sixth = "R";

	//create a character table
	vector <int> charTable(127,0);

	// populate the table
	for (int i = 0; i < first.length(); i++)
	{
		charTable[first[i]] = 1;
	}

	for (int i = 0; i < second.length(); i++)
	{
		charTable[second[i]] = 2;
	}

	for (int i = 0; i <third.length(); i++)
	{
		charTable[third[i]] = 3;
	}


	for (int i = 0; i < fourth.length(); i++)
	{
		charTable[fourth[i]] = 4;
	}

	for (int i = 0; i < fifth.length(); i++)
	{
		charTable[fifth[i]] = 5;
	}

	for (int i = 0; i < sixth.length(); i++)
	{
		charTable[sixth[i]] = 6;
	}


	// create variables for input
	string input;
	char currentChar,previousChar;
	long long answer;
	int currentValue, tableValue, previousTableValue;

	// read input
	while (cin >> input)
	{
		answer = 0;
		//vector <bool> status(7, false);

		for (int i = 0; i < input.length(); i++)
		{
			currentChar = input[i];
			currentValue = (int)currentChar;
			tableValue = (int)charTable[currentChar];

			if (i==0)
			{
				if (tableValue!=0)
				answer = (answer * 10) + tableValue;
			}

			else
			{
				previousChar = input[i - 1];
				previousTableValue = (int)charTable[previousChar];
				if (currentChar != previousChar  && tableValue != previousTableValue)
				{
					if (tableValue != 0)
						answer = (answer * 10) + tableValue;
				}
			}
		}

		if (answer > 0)
		{
			cout << answer << endl;
		}

		else
		{
			cout << " " << endl;
		}
	}

	return 0;
}
