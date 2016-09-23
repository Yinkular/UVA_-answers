//**************************************************************
//                   Project The Decoder (Extra Credit)
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/06/2016
//***************************************************************
//		The program reads input from a data file containing 
//		a string in its wrong form and the program is meant
//		to decipher the wrong text and print the correct string.
//
//		Input format -> Text file, each line contains a data string
//						which is to be deciphered.
//		Output Format -> String which corresponds to the original
// 						 text intended.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// create variables
	string rawWord, decodedWord;
	char currentChar, newCharacter;
	int asciiValue, wordLength;

	// accept input till no input
	while (getline(cin, rawWord))
	{
		//initialize decoded word to empty string at each run
		decodedWord = "";

		//get the length of the current word
		wordLength = rawWord.length();

		// run a loop to go through each character
		for (int i = 0; i < wordLength; i++)
		{
			// retrieve the current char
			currentChar = rawWord[i];
			
			//convert the current character to it's ascii equivalent
			asciiValue = (int) currentChar;

			//convert asciiValue to decoded value;
			asciiValue -= 7;

			// convert from ascii to character
			newCharacter = (char)asciiValue;

			//concatenate with new string
			decodedWord += newCharacter;
		}

		//print the new string
		cout << decodedWord << endl;
	}

	return 0;
}