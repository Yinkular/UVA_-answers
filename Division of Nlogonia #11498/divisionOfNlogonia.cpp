#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	// create variables
	int number, N,M, X,Y;

	while (cin >> number)
	{
		// check stop  case
		if (number == 0)
		{
			break;
		}


		// get the division point N and M
		cin >> N >> M;

		// run a looop for the number of test  cases per set
		for (int i = 1; i <= number; i++)
		{
			// get  X and Y coordinates of residence
			cin >> X >> Y;

			if (X == N || Y == M)
			{
				cout << "divisa" << endl;
			}

			else if (X > N && Y > M)
			{
				cout << "NE" << endl;
			}

			else if (X < N && Y> M)
			{
				cout << "NO" << endl;
			}

			else if (X < N && Y < M)
			{
				cout << "SO" << endl;
			}

			else if (X > N && Y < M)
			{
				cout << "SE" << endl;
			}
		}
	}
}