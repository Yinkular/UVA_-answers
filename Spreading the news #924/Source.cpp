#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> list,int start, int &maxDaily, int &firstBoom)
{
	vector <int> distance(list.size(), -1);
	queue<int> Q;

	Q.push(start);
	distance[start] = 0;

	int current;

	while (!Q.empty()) // run BFS updating distance
	{
		current = Q.front();

		for (int i = 0; i < list[current].size(); i++)
		{
			int currentFriend = list[current][i];

			if (distance[currentFriend] == -1)
			{
				distance[currentFriend] = distance[current] + 1;
				Q.push(currentFriend);
			}
		}

		Q.pop();
	}

	vector<int> frequency(distance.size());

	for (int i = 0; i < distance.size(); i++) // count the number of each nodes at each depth
	{
		if (distance[i] == -1) // if node wasn't reached
			continue;

		frequency[distance[i]]++;
	}

	int max = 0;

	for (int i = 1; i < frequency.size(); i++) // get the maximum occurence 
	{
		if (frequency[i] > max)
		{
			max = frequency[i];

			firstBoom = i;
			maxDaily = max;
		}
	}

}

int main()
{
	int employees;
	cin >> employees;

	vector<vector<int>> adjList(employees);

	for (int i = 0; i < employees; i++)
	{
		int noOfFriends;
		cin >> noOfFriends;

		for (int j = 0; j < noOfFriends; j++) // accept input into adjacency list
		{
			int friendId;
			cin >> friendId;

			adjList[i].push_back(friendId);
		}
	}

	int testCases, start, maxDaily, firstBoom;
	cin >> testCases;

	for (int i = 0; i < testCases; i++) // run through test cases
	{
		cin >> start;
		maxDaily = firstBoom = 0;

		BFS(adjList, start, maxDaily, firstBoom); // pass list, start point, and maxDaily, firstBoom by reference

		if (firstBoom == 0)
		{
			cout << "0" << endl;
		}

		else
		{
			cout << maxDaily << " " << firstBoom << endl;
		}
	}

	return 0;
}