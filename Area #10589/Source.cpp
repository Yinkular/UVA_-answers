#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define float double

using namespace std;
typedef pair<int, int> edge;

bool euclideanDistance(vector<edge> square, float X, float Y, int sideSize)
{
	float xCoor, yCoor, answer;
	bool status = true;

	for (int i = 0; i < square.size(); i++) // run through square sides
	{
		xCoor = pow(square[i].first - X, 2);
		yCoor = pow(square[i].second - Y, 2);

		answer = sqrt(xCoor + yCoor); //  get distance

		if (answer > sideSize) // check if distance is within limit
		{
			status = false;
			break;
		}
	}

	return status;
}

int main()
{
	int N, a;

	while (cin >> N >> a && N != 0) // accept input till N is 0
	{
		float X, Y, answer;
		int M = 0;

		vector<edge> square(4); // create four points of the aquare
		square[0] = { 0, 0 };
		square[1] = { a, 0 };
		square[2] = { 0, a };
		square[3] = { a, a };


		for (int i = 0; i < N; i++)
		{
			cin >> X >> Y;
			if (euclideanDistance(square, X, Y, a)) // call euclidean function with square sides and cooridnates
			{
				M++;
			}
		}

		answer = float(M) * float(pow(a,2)) / float(N);

	
		cout << fixed << setprecision(5) << answer << endl;
	}
}