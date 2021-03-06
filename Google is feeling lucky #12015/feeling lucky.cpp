#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
	// variables to hold values
	int noOfUrlsPerCase = 10, testCases, totalUrls;

	// accept number of test cases
	cin >> testCases;

	// if there is a test case to work on
	if (testCases > 0)
	{
		//get total number of urls in the data file
		totalUrls = testCases * noOfUrlsPerCase;

		// container to hold data
		vector<string> url(totalUrls);
		vector<int> rating(totalUrls);
		vector<int> eachMax(testCases);
		int currentGroup = 0;

		int max = 0;

		// get all data from text file
		for (int i = 0; i < totalUrls; i++)
		{
			cin >> url[i] >> rating[i];

			// check if the current url rating is greater than previous max
			if (rating[i] > max)
			{
				max = rating[i];
			}

			// check if we are at the end of current data set
			// if yes push max to the container
			// reinitialize max to zero for next set
			if ((i + 1) % 10 == 0)
			{
				eachMax[currentGroup] = max;
				max = 0;
				currentGroup++;
			}
		}

		// variable to hold current group we are working with
		currentGroup = 0;

		//print out answers
		for (int i = 0; i < totalUrls; i++)
		{
			// check if we are the beginning of a new group
			if ((i + 1) % 10 == 1)
			{
				cout << "Case#" << currentGroup + 1 << endl;
			}

			// check if current rating is equal to the max of the current group
			if (rating[i] == eachMax[currentGroup])
			{
				cout << url[i] << endl;
			}

			if ((i + 1) % 10 == 0)
			{
				currentGroup++;
			}
		}
	}

	return 0;
}