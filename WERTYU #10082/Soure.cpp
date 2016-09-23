//**************************************************************
//                   Project #3 WERTY
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/13/2016
//***************************************************************
//      The program reads input from a data file containing 
//      a string in its wrong form and the program is meant
//      to decipher the wrong text and print the correct string.
//
//      Input format -> Text file, each line contains a data string
//                      which is to be deciphered.
//      Output Format -> String which corresponds to the original
//                       text intended.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
	string fullKeyboard, altKeyboard;


	fullKeyboard = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`-=[]\\;',./";
	altKeyboard = " VXSWDFGUHJKNBIO EARYCQZT 9`12345678 0-P[]L;M,.";


	// create a char table using the  original keyboard and alternate keyboard
	vector <char> table(127);

	//populate the table using the strings
	for (int i = 0; i < fullKeyboard.length(); i++)
	{
		table[fullKeyboard[i]] = altKeyboard[i];
	}


	

	// create variables
	string wrongWord, reversedWord;
	char currentChar;
	int wordLength;

	while (getline(cin, wrongWord))
	{
		reversedWord = "";

		// get the length of the word
		wordLength = wrongWord.length();

		//loop through each character in the word
		for (int i = 0; i < wordLength; i++)
		{
			currentChar = wrongWord[i];

			if (currentChar == ' ')
			{
				reversedWord += " ";
			}

			else
			{
				reversedWord += table[currentChar];
			}
		}

		cout << reversedWord << endl;
	}
	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
// Signature ___________________