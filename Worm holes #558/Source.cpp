#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> edgePair; // pair for an edge node number and weight

void bellman_ford(vector<vector<edgePair>> adjList)
{
	vector<int> distance(adjList.size(), INT_MAX);
	vector<int> predecessor(adjList.size(), -1);
}

int main()
{
	int testCases, n, m;

	cin >> testCases;

	cout << testCases << endl;

	for (int i = 1; i <= testCases; i++)
	{
		cin >> n >> m; // get number of stars and number of wormholes

		int x, y, t; // x = source, y = destination, t= time difference.
		vector<vector<edgePair>> adjList(n); // create an adjeacency list for edges and weights
		edgePair edge;

		cout << n << " " << m << endl;

		for (int j = 0; j < n; j++)
		{
			cin >> x >> y >> t;
			edge = make_pair(y, t); // make a pair of edgesa and time
			adjList[x].push_back(edge); // push the pair to the list

			cout << x << " " << y << " " << t << endl;
		}
	}
	return 0;
}