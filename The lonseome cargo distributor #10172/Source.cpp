//**************************************************************
//                   Project : #12 Lonesome Cargo
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/26/2016
//***************************************************************
//      The program tries to calcuiate the time taken to assign all 
//		cargo in an airport to their appropriate stations.
//
//      Input format -> Text file, begins with a line containing, 
//		the number of sets, followed by another line containing
//		number of stations, carrier size, and the biggest platform
//		size for any station
//
//      Output Format -> am integer which represents time taken to
//		assign all cargo to appropriate stations.
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define endl "\n";

using namespace std;


int main()
{
	// variables for input
	int noOfSets, numberOfStations, carrierCapacity, platformB, cargoQueued, number;

	cin >> noOfSets;

	//loop through sets
	for (int i = 1; i <= noOfSets; i++)
	{
		// get input for stations and others
		cin >> numberOfStations >> carrierCapacity >> platformB;

		// create a  stack using carrire size
		stack<int> carrier;

		// create an array of queues to store loads on platform b
		vector <queue<int>> platform(numberOfStations + 1);


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
			}
		}

		// unloading and loading of cargo to various stations
		// a circular (endless loop) runs round the stations

		// variables fo stations
		int currentStation , station=1;
		bool status = true;

		// variables for offloading and loading
		int currentCargo;

		// time taken for each set;
		int timeTaken = 0;

		while (true)
		{
			// formula to get current station loops through the stations in a circular way
			currentStation= ((station - 1) % numberOfStations)+1;

			// unload at the current station
			// while te carrier is not empty try to offload its contents
			while (!carrier.empty())
			{
				// get the topmost cargo
				currentCargo = carrier.top();

				// if the cargo is meant for this station
				if (currentCargo == currentStation)
				{
					// delete it
					carrier.pop();
					timeTaken++;
				}

				// if the cargo is meant for another station
				else
				{
					// check if platform from current staion isn't full
					if (platform[currentStation].size() < platformB)
					{
						// push unto platform b
						platform[currentStation].push(currentCargo);

						// delete it from the carrier
						carrier.pop();

						// increase time taken
						timeTaken++;
					}

					// if platform is full
					else
					{
						break;
					}
				}
			}
			
			//load back to the carrier if carrier isn't full and queue isn't empty
			while (carrier.size() < carrierCapacity && platform[currentStation].size() > 0)
			{
				// load from platform b to the carrier
				carrier.push(platform[currentStation].front());

				// delete from the queue
				platform[currentStation].pop();
				
				// increase time taken
				timeTaken++;
			}

			// check if all queues are empty
			for (int l = 1; l <= numberOfStations; l++)
			{
				if (!platform[l].empty())
				{
					status = false;
					break;
				}

				else
				{
					status = true;
				}
			}

			// break out of the loop if all queues are empty and carrier is empty
			if (status && carrier.empty())
			{
				break;
			}

			// takes two minutes to next station
			timeTaken += 2;

			// go to the next station
			station++;
		}

		cout << timeTaken << endl;
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________