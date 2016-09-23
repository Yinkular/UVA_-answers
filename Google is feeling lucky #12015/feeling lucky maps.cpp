#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	// variable to stor values
	int testCases, noOfCasesPerTest = 10, totalUrls, ranking,max=0;
	string url;
	map <int, string> urlRanking;

	

	// retrieve first line which corresponds to number of test cases
	cin >> testCases;

	vector <int> eachMax(testCases);
	
	// total number of urls
	totalUrls = testCases * noOfCasesPerTest;

	cout << totalUrls << endl;

	// retrieve all the data from the text file
	for (int i = 0; i < totalUrls; i++)
	{
		// store current url and corresponding rank to a variable
		cin >> url >> ranking;

		// use ranking as key to store url in a map
		urlRanking[ranking] = url;

		// get current max
		if (ranking > max)
		{
			max = ranking;
		}

		// shift throught test cases
		if ((i + 1) % 10 == 0)
		{
			eachMax.push_back(max);
			max = 0;
		}
	}

	map<int,string> ::iterator it = urlRanking.begin();

	for (it ; it != urlRanking.end(); it++)
	{
		cout << it->first << "-" << it->second << endl;
	}
	
	return 0;
}