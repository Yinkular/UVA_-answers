//**************************************************************
//                   Project #6 Kindergaten counting game
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/08/2016
//***************************************************************
//		The program reads input from a data file containing 
//		strings and  outputs the number of words containing
//		only alphabets per line.
//
//		Input format -> Text file, containing a string per line
//		Output Format -> an integer corresponding to the number 
//						 of words in the string
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	// create variables
	string sentence, word;
	int wordCount, length;
	char currentChar;
	vector<string> wordContainer;

	// while loop to run till there is no sentence
	while (getline(cin, sentence))
	{
		// intiialize word count to 0
		wordCount = 0;
		word = "";
		wordContainer.clear();

		// get the length of the current sentence
		length = sentence.length();

		// loop through the sentence
		for (int i = 0; i < length; i++)
		{
			// get the current character
			currentChar = sentence[i];

			// if the current character is an alphabet 
			// concatenate with string
			if (isalpha(currentChar))
			{
				word += currentChar;
			}

			else
			{
				if (word != "")
				wordContainer.push_back(word);
				
				word = "";
			}

		}

		wordCount = wordContainer.size();
		cout << wordCount << endl;
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________