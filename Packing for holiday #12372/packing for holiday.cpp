#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//create variables
	int testCases, width, length, height;
	bool status;

	//get number of test cases
	cin >> testCases;

	for (int i = 1; i <= testCases; i++)
	{
		status = false;

		cin >> length >> width >> height;

		if (length <= 20 && width <= 20 && height <=20)
		{
			status = true;
		}

		if (status)
		{
			cout << "Case " << i << ": good" << endl;
		}

		else
		{
			cout << "Case " << i << ": bad" << endl;
		}

	}

	return 0;
}