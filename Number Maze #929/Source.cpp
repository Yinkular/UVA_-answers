//**************************************************************
//                   Project: #24 Number Maze
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 12/6/2016
//***************************************************************
//		The program tries to predict the shortest route from the top
//		left corner to the right bottom corner.
//		
//		Input format ->  Lines containing integers that represent the
//						structure of a the matrix.
//		Output Format -> Value of the shortest path.
//*****************************************************************
// Program Complexity -> O(V+E)
//*****************************************************************



#include  <iostream>
#include <vector>
#include <queue>
#include <functional>
#define MAXINT 2147483640

using namespace std;

typedef pair<int, int> edge; //an edge is in the form (weight, node number)

int djisktra(int start, vector<vector<edge>> adjList, int size)
{
	priority_queue<edge, vector<edge>, greater<edge>> pq; // create priority queue that uses weights
	pq.push({ start, 0 }); // push start point

	vector<int> distance(size, MAXINT); // initialize all distances to a large value
	distance[0] = start; // firxt distance =0

	while (!pq.empty()) // iterate through queue
	{
		edge node = pq.top();
		int dist = node.first;
		int nodeNumber = node.second;

		for (int i = 0; i < adjList[nodeNumber].size(); i++) // loop through adjacent nodes
		{
			edge currentAdjacent = adjList[nodeNumber][i];
			int weight = currentAdjacent.first;
			int vertex = currentAdjacent.second;

			if (distance[vertex] > distance[nodeNumber] + weight) //  relaxation
			{
				distance[vertex] = distance[nodeNumber] + weight;
				pq.push({ distance[vertex], vertex });
			}
		}

		pq.pop();
	}

	return distance[size - 1]; // return answer
}

int main()
{
	int testCases, row, column;

	cin >> testCases;

	for (int i = 1; i <= testCases; i++)
	{
		cin >> row >> column;

		vector<vector<int>> matrix(row, vector<int>(column)); // create matrix

		// read in data
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < column; c++)
			{
				cin >> matrix[r][c];
			}
		}

		// create an adjacency list 
		vector<vector<edge>> adjList(row*column);

		int nodeNumber, rightNodeNumber, bottomNodeNumber, rightnodeWeight, bottomNodeWeight;
		edge nodePair;

		// run a loop to create graph structure in an adjacency list
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < column; c++)
			{
				//(currentrow * columnsize) + column **formula to convert matrix index to array like indexing
				nodeNumber = r*column + c;

				if (c + 1 <= column - 1) // check boundaries
				{
					rightNodeNumber = r*column + (c + 1);
					rightnodeWeight = matrix[r][c + 1];
					// make a pair of right node and weight then push back
					nodePair = { rightnodeWeight, rightNodeNumber };
					adjList[nodeNumber].push_back(nodePair);
				}

				if (r + 1 <= row - 1) // check boundaries
				{
					bottomNodeNumber = ((r + 1) * column) + c;
					bottomNodeWeight = matrix[r + 1][c];
					// make a pair of bottom node and weight then push back
					nodePair = { bottomNodeWeight, bottomNodeNumber };
					adjList[nodeNumber].push_back(nodePair);
				}
			}
		}

		int answer = djisktra(matrix[0][0], adjList, row*column); // call djsisktra using the start point, list and size of matrix
		cout << answer << endl;
	}

	return 0;
}