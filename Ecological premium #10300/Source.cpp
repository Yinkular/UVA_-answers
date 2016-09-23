//**************************************************************
//                   Project: #9 Ecological Premium
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/13/2016
//***************************************************************
//      The program reads input from a file, this input are sets
//		of  integers denoting parameters for each farmer and tries
//		to calculate the budget allocated by the government for each
//		group of farmers
//
//      Input format -> Text file, contains groups of farmers parameters
//      Output Format -> The budget allocated for each group of farmers
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// create variables
	int testCases, noOfFarmers;
	float farmSize, noOfAnimals, envFriendliness, intBudget,space, premium, answer, floatBudget;

	cin >> testCases;

	// loop through test cases
	for (int i = 1; i <= testCases; i++)
	{
		// get no of farmers in each testcase
		cin >> noOfFarmers;

		floatBudget = 0;

		//loop through each line of farmers
		for (int j = 1; j <= noOfFarmers; j++)
		{
			// read in values fo each farmer
			cin >> farmSize >> noOfAnimals >> envFriendliness;

			// calculate all variables
			space = farmSize / noOfAnimals;

			premium = space * envFriendliness;

			answer = premium * noOfAnimals;

			// add to previous answer
			floatBudget += answer;
		}

		// make sure value is an integer
		intBudget = (int)floatBudget;

		cout << intBudget << endl;
	}
	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________
