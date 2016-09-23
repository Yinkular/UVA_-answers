#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int main()
{
	// variaqbles for input
	int noOfSets, numberOfStations, carrierCapacity, platformB, cargoQueued, number;

	cin >> noOfSets;

	//loop mthrough sets
	for (int i = 1; i <= noOfSets; i++)
	{
		// get input for stations and others
		cin >> numberOfStations >> carrierCapacity >> platformB;

		// create a  stack using carrire size
		stack<int> carrier;

		// create an array of queues to store loads on platform b
		vector <queue<int>> platform(numberOfStations+1);


		// loop through each station and store contents of platforms in queue
		for (int j = 1; j <= numberOfStations; j++)
		{
			// get cargo queued at current station
			cin >> cargoQueued;

			// store the cargo queued in the queue for the current station
			for (int k = 1; k <= cargoQueued; k++)
			{
				cin >> number;

				platform[j].push(number);
				cout << number << " ";
			}

			cout << endl;
		}

	}
	

	system("pause");
	return 0;
}