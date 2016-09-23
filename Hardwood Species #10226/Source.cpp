//**************************************************************
//                   Project: #11 Hardwood Species
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/22/2016
//***************************************************************
//      The program tries to calcuiate if  a trip can be completed
//		back and forth based on restricted constraints which are
//		the charging stations if the traveller is usin an electric 
//		vehicle.
//
//      Input format -> Text file containing a list of trees in a 
//						population
//      Output Format -> Represnation by percentage of each species 
//						in the population alphabetically.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************


#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main()
{
	// declare variables
	int testCases, numberOfTrees;
	string emptyLine, currentTree;

	cin >> testCases;
	getline(cin, emptyLine);
	getline(cin, emptyLine);

	for (int i = 1; i <= testCases; i++)
	{
		// initialize number of trees for each test case to zero
		numberOfTrees = 0;

		// create map of pair string and int
		map<string, int> trees;

		// create an iterator for our tree
		map<string, int>::iterator it;

		// read till there is an empty line
		while (getline(cin, currentTree))
		{
			// test if current string is an empty line
			if (currentTree.length() == 0)
			{
				break;
			}

			// check if current tree has been inserted
			it = trees.find(currentTree);

			// if it hasn't been inserted
			if (it == trees.end())
			{
				// insert the tree with an integer value of one
				trees.insert(pair<string, int>(currentTree, 1));
			}

			// if tree exists already
			else
			{
				// use current tree as key and increase the value of the position by one
				trees[currentTree]++;
			}

			// increase count of trees by one
			numberOfTrees++;
		}

		// point the iterator to the beginning of the map
		it = trees.begin();

		int currentTreeCount=0;
		float answer=0;

		// set the precison of our answers
		cout << setprecision(4) << fixed;

		// loop through the map
		for (it; it != trees.end(); it++)
		{
			// get the numbre of the current tree
			currentTreeCount = it->second;

			// calculate the percentage
			answer = (float(currentTreeCount) / float(numberOfTrees)) * 100;

			// print out the tree and it's percentage
			cout << it->first << " " << answer << endl;
		}

		// print out needed new line
		if (i< testCases)
			cout << endl;
	}
	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________