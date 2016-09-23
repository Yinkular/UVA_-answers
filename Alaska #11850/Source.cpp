//**************************************************************
//                   Project Extra Credit (Alaska)
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 09/22/2016
//***************************************************************
//      The program tries to calcuiate if  a trip can be completed
//		back and forth based on restricted constraints which are
//		the charging stations if the traveller is usin an electric 
//		vehicle.
//
//      Input format -> Text file, begins with a line containingn, 
//		a positive numberindicating the number of charging stations.
//		nlinesfollow, each giving the location of a filling station on
//		the highway, including the one in Dawson City

//      Output Format -> a line containing ‘POSSIBLE’ if Brenda can
//		 make the trip. Otherwise 'IMPOSSIBLE'
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************


#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n";

using namespace std;

int main()
{
	// variable for number of charging stations
	int  chargingStations, currentDistance, nextDistance, distancePerCharge;

	distancePerCharge = 200;

	// bool to check if it is possible or not
	bool possibility;

	// loop through the data until a charging station value is 0
	while (cin >> chargingStations && chargingStations != 0)
	{
		possibility = true;

		// vector for the dta
		vector<int> distances(chargingStations);

		// loop through the charging station
		for (int i = 0; i < chargingStations; i++)
		{
			cin >> distances[i];
		}

		// sort the distance
		sort(distances.begin(), distances.end());

		// calculate if it is possible or not
		for (int i = 0; i < (chargingStations-1); i++)
		{
			currentDistance = distances[i];
			nextDistance = distances[i +1];

			if (nextDistance > (currentDistance + distancePerCharge))
			{
				possibility = false;
			}

		}

		// at this point we know it can get to the destination
		// to calculate if it can get back
		int  distanceFromLastStattion;
		distanceFromLastStattion = 1422 - distances[chargingStations - 1];

		if ((2 * distanceFromLastStattion) > distancePerCharge)
		{
			possibility = false;
		}
		
		// print out answer
		if (possibility)
		{
			cout << "POSSIBLE" << endl;
		}

		else
		{
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________