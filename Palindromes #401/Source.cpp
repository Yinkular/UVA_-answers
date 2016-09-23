//**************************************************************
//                   Project #4 Palindromes
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/08/2016
//***************************************************************
//		The program reads input from a file, this input are sets
//		of strings and checks if the string is mirrored, palindrome
//		or both
//
//		Input format -> Text file,  each line contains a string.
//		Output Format -> A string that shows if the corresponding
//						string is mirrored palindrome or both.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	//preproccess data
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	string reverse = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

	// length of the alphabet string
	int length = alphabet.length();

	// vector to store makeshift table
	vector <char> table(127);

	//use the above strings to create a mini ascii table
	for (int i = 0; i < length; i++)
	{
		//cout << alphabet[i] << "=>" << reverse[i] << endl;

		// use the ascii conversion of  each element to store it's reverse
		table[alphabet[i]] = reverse[i];
	}

	string word, mirrorWord;
	
	while (cin >> word)
	{
		mirrorWord = "";

		// create variables
		int wordLength = word.length();
		bool palindrome = true, mirror = true;

		// check for palindrome
		for (int i = 0; i < wordLength / 2; i++)
		{
			if (word[i] != word[(wordLength - 1) - i])
			{
				palindrome = false;
				break;
			}
		}

		// check for mirror
		//reverse the string using reverse characters
		for (int j = wordLength-1; j >=0; j--)
		{
			mirrorWord += table[word[j]];
		}

		// compare if the two strings are still equal
		if (word.compare(mirrorWord)!=0)
		{
			mirror = false;
		}

		// if it is a palindrome and not mirrored
		if (palindrome && !mirror)
		{
			cout << word << " -- is a regular palindrome." << endl;
		}

		// if it is a mirror and not palidnrome
		else if (mirror && !palindrome)
		{
			cout << word << " -- is a mirrored string." << endl;
		}

		// if is both palindrome and mirror
		else if (palindrome && mirror)
		{
			cout << word << " -- is a mirrored palindrome." << endl;
		}

		else if (!palindrome)
		{
			cout << word << " -- is not a palindrome." << endl;
		}

		cout << endl;
		
	}

	return 0;
}
// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________