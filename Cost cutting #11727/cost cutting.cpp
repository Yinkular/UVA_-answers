#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//create variables
	int testCases, employee1, employee2, employee3;

	//read no of test cases
	cin >> testCases;

	for (int i = 1;i<= testCases; i++)
	{
		// create a vector to store the salaries
		vector <int> salaries(3);

		// read salary of the three employees
		cin >> employee1 >> employee2 >> employee3;
		
		//push the salaries into the vector
		salaries[0] = employee1;
		salaries[1] = employee2;
		salaries[2] = employee3;

		// sort the salary vector
		sort(salaries.begin(), salaries.end());

		// the middle value is the person to be kept
		cout << "Case " << i<<": "<< salaries[1] << endl;
	}

	return 0;
}