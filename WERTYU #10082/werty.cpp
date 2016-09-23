//**************************************************************
//                   Project #3 WERTY
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
// Program Complexity -> O(n^2)
//*****************************************************************

#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
	char fullKeyboard[47];

	fullKeyboard[0] = 'A';
	fullKeyboard[1] = 'B';
	fullKeyboard[2] = 'C';
	fullKeyboard[3] = 'D';
	fullKeyboard[4] = 'E';
	fullKeyboard[5] = 'F';
	fullKeyboard[6] = 'G';
	fullKeyboard[7] = 'H';
	fullKeyboard[8] = 'I';
	fullKeyboard[9] = 'J';
	fullKeyboard[10] = 'K';
	fullKeyboard[11] = 'L';
	fullKeyboard[12] = 'M';
	fullKeyboard[13] = 'N';
	fullKeyboard[14] = 'O';
	fullKeyboard[15] = 'P';
	fullKeyboard[16] = 'Q';
	fullKeyboard[17] = 'R';
	fullKeyboard[18] = 'S';
	fullKeyboard[19] = 'T';
	fullKeyboard[20] = 'U'; 
	fullKeyboard[21] = 'V';
	fullKeyboard[22] = 'W';
	fullKeyboard[23] = 'X';
	fullKeyboard[24] = 'Y';
	fullKeyboard[25] = 'Z';
	fullKeyboard[26] = '0';
	fullKeyboard[27] = '1';
	fullKeyboard[28] = '2';
	fullKeyboard[29] = '3';
	fullKeyboard[30] = '4';
	fullKeyboard[31] = '5';
	fullKeyboard[32] = '6';
	fullKeyboard[33] = '7';
	fullKeyboard[34] = '8';
	fullKeyboard[35] = '9';
	fullKeyboard[36] = '`';
	fullKeyboard[37] = '-';
	fullKeyboard[38] = '=';
	fullKeyboard[39] = '[';
	fullKeyboard[40] = ']';
	fullKeyboard[41] = '\\';
	fullKeyboard[42] = ';';
	fullKeyboard[43] = '\'';
	fullKeyboard[44] = ',';
	fullKeyboard[45] = '.';
	fullKeyboard[46] = '/';
	

	char altKeyboard[47];

	altKeyboard[0] = ' ';
	altKeyboard[1] = 'V';
	altKeyboard[2] = 'X';
	altKeyboard[3] = 'S';
	altKeyboard[4] = 'W';
	altKeyboard[5] = 'D';
	altKeyboard[6] = 'F';
	altKeyboard[7] = 'G';
	altKeyboard[8] = 'U';
	altKeyboard[9] = 'H';
	altKeyboard[10] = 'J';
	altKeyboard[11] = 'K';
	altKeyboard[12] = 'N';
	altKeyboard[13] = 'B';
	altKeyboard[14] = 'I';
	altKeyboard[15] = 'O';
	altKeyboard[16] = ' ';
	altKeyboard[17] = 'E';
	altKeyboard[18] = 'A';
	altKeyboard[19] = 'R';
	altKeyboard[20] = 'Y';
	altKeyboard[21] = 'C';
	altKeyboard[22] = 'Q';
	altKeyboard[23] = 'Z';
	altKeyboard[24] = 'T';
	altKeyboard[25] = ' ';
	altKeyboard[26] = '9';
	altKeyboard[27] = '`';
	altKeyboard[28] = '1';
	altKeyboard[29] = '2';
	altKeyboard[30] = '3';
	altKeyboard[31] = '4';
	altKeyboard[32] = '5';
	altKeyboard[33] = '6';
	altKeyboard[34] = '7';
	altKeyboard[35] = '8';
	altKeyboard[36] = ' ';
	altKeyboard[37] = '0';
	altKeyboard[38] = '-';
	altKeyboard[39] = 'P';
	altKeyboard[40] = '[';
	altKeyboard[41] = ']';
	altKeyboard[42] = 'L';
	altKeyboard[43] = ';';
	altKeyboard[44] = 'M';
	altKeyboard[45] = ',';
	altKeyboard[46] = '.';

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
				//search for character in original alphabet list
				for (int j = 0; j < 47; j++)
				{
					if (currentChar == fullKeyboard[j])
					{
						reversedWord += altKeyboard[j];
					}
				}
			}
		}

		cout << reversedWord << endl;
	}
	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
// Signature ___________________