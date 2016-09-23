//**************************************************************
//                   Project #5 Group Reverse
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/08/2016
//***************************************************************
//		The program reads input from a data file containing 
//		a string and  an integer, and tries to reverse 
//		substrings of the string using the integer as a 
//		block size.
//
//		Input format -> Text file, containing an integer and abort
//						a string per line
//		Output Format -> single string per line but completely reversed
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	// create variables
	int noOfGroup;
	string word,reversedWord, newWord, sub;

	while (cin >> noOfGroup)
	{
		//condition to terminate loop
		if (noOfGroup == 0)
		{
			break;
		}

		// initialize variables to empty string at the beginning of each loop
		word = "";
		reversedWord = "";
		newWord = "";
		sub = "";

		// retrieve the word to be manipulated
		cin >> word;

		// variables for word grouping
		int length, charsPerGroup;
		
		// get the length of the word
		length = word.length();

		// get the number of characters per group
		charsPerGroup = length / noOfGroup;

		// reverse the complete word
		for (int i = (length - 1); i >= 0; i--)
		{
			reversedWord += word[i];
		}

		// get the sub strings
		for (int j = length-1; j >= 0; j -= charsPerGroup)
		{
			// get the reversed substring
			sub = reversedWord.substr((j - charsPerGroup)+1, charsPerGroup);
			
			cout << sub;
		}
		cout << endl;
	}
	return 0;
}
// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________