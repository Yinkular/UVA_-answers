//**************************************************************
//                   Project: #23 Bicoloring
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 11/22/2016
//***************************************************************
//		The program tries to check if all the nodes in a graph can be 
//		bicolored or not.
//		
//		Input format ->  Lines containing integers that represent the 
//						structure of the graph.
//		Output Format -> If the graph is bicolorobale or not.
//*****************************************************************
// Program Complexity -> O(V+E)
//*****************************************************************

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool biColor(vector<vector<int>> graph)
{

	enum color{ white, black, red };
	vector<color> nodeColor(graph.size(), white);

	int start = 0;
	nodeColor[start] = black; // set first node to black

	queue<int> Q;
	Q.push(start);

	int front;
	while (!Q.empty())
	{
		front = Q.front();

		for (int i = 0; i < graph[front].size(); i++)
		{
			if (nodeColor[graph[front][i]] == white) // if it hasnt't been visited
			{
				color alternate;
				alternate = nodeColor[front] == black ? red : black; // set color to alternate color of parent

				nodeColor[graph[front][i]] = alternate;

				Q.push(graph[front][i]);
			}

			else if (nodeColor[graph[front][i]] == nodeColor[front]) // if child node has been recolored and has the same color
			{
				return false;
			}
		}
		Q.pop();
	}

	return true;
}

int main()
{
	int nodes, edges;

	while (cin >> nodes && nodes != 0)
	{
		//cout << nodes << endl;
		cin >> edges;

		//cout << edges << endl;

		vector<vector<int>> graph(nodes);

		int node1, node2;
		for (int i = 0; i < edges; i++)
		{
			cin >> node1 >> node2;

			//cout << node1  << " "<< node2 << endl;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}

		bool answer;

		answer = biColor(graph);

		if (answer)
		{
			cout << "BICOLORABLE." << endl;
		}

		else
		{
			cout << "NOT BICOLORABLE." << endl;
		}
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________