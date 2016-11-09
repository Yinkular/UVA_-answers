//**************************************************************
//                   Project: #19 Vertex
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 10/27/2016
//***************************************************************
//   	Program searches a directed graph for vertices which are 
//		inaccessible from a given startingvertex.
//
//      Input format -> Contains number of vertices and the other
//						vertices they point to. Followed by a start
//						point for a traversal.
//      Output Format -> Number of inaccesible vertices from the 
//						  start point and the vertices that can't reached
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	int noOfVertex;
	enum color{ white, grey, black };

	while (cin >> noOfVertex && noOfVertex != 0)
	{
		// create a vector of vertices with indexing from 1
		vector<vector<int>> vertices(noOfVertex + 1);

		int currentVertex;

		// get the current vertex
		while (cin >> currentVertex && currentVertex != 0)
		{
			int pointedVertex;
			// loop through all vertex pointed to
			while (cin >> pointedVertex && pointedVertex != 0)
			{
				vertices[currentVertex].push_back(pointedVertex);
			}

			//cout << endl;
		}

		int noOftest;
		cin >> noOftest;

		for (int i = 1; i <= noOftest; i++)
		{
			int start, count =0;
			cin >> start;
			
			// create a vector for each vertex and initialize to white
			vector<color> vertexColor(noOfVertex + 1, white); 

			queue<int> Q;

			Q.push(start); // insert first node to be visited into stack

			while (!Q.empty()) // while queue isn't empty and vertec not visited
			{
				int current = Q.front();
				//vertexColor[current] = black;

				for (int i = 0; i < vertices[current].size(); i++)
				{
					int pointedTo = vertices[current][i];
					// if it hasn't been seen add to queue
					if (vertexColor[pointedTo] == white)
					{
						Q.push(pointedTo);
						vertexColor[pointedTo] = grey;
						count++;// count number of elements seen
					}
				}

				Q.pop();// remove the visited node from the queue
			}

			int notReached = noOfVertex - count; // get number of not visited nodes
			cout << notReached ;

			if (notReached > 0) 
			{
				for (int i = 1; i < vertexColor.size(); i++)
				{
					if (vertexColor[i] != grey)
					{
						cout << " "<< i ;
					}
				}
			}
			cout << endl;
		}
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________