//**************************************************************
//                   Project: #21 Graph Connectivity
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 11/3/2016
//***************************************************************
//   	Program finds number of maximally connected subgraphs
//		in a given graph.
//
//      Input format -> Number of nodes, and the connected edges
//      Output Format -> Number of maximally connected subgraphs.
//*****************************************************************
// Program Complexity -> O(V+E)
//*****************************************************************

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define asciiFirst 65;

using namespace std;

class graph
{
public:
	graph(int);
	~graph();
	void insert(int, int);
	void dfs(int);
	void dfsVisit(int);
	int answer();


private:
	int size;
	int count;
	enum color { white, grey, black };
	vector<vector<int>> connectedGraph;
	vector<color> nodeColors;
};

graph::graph(int size)
{
	this->size = size;

	connectedGraph.resize(this->size + 1);
	nodeColors.resize(this->size + 1);

	// initialize all nodes to white
	for (int i = 1; i <= size; i++)
	{
		nodeColors[i] = white;
	}

	count = 0;
}

graph::~graph()
{
}

// function to insert into graph
void graph::insert(int edge1, int edge2)
{
	connectedGraph[edge1].push_back(edge2);
}

// function for depth first search
void graph::dfs(int node)
{
	// traverse from the index of the passed node
	for (int i = node; i <= size; i++)
	{
		if (nodeColors[i] == white) // if node hasn't been visited
		{
			dfsVisit(i);
			++count;
		}
	}

}

void graph::dfsVisit(int node)
{
	// paint the passed node grey
	nodeColors[node] = grey;

	for (int i = 0; i < connectedGraph[node].size(); i++)// loop to get all neighbors
	{
		int adjacentEdge = connectedGraph[node][i];

		if (nodeColors[adjacentEdge] == white)
		{
			dfsVisit(adjacentEdge); // recursively visit neighbor nodes
		}
	}

	nodeColors[node] = black; // set the visited node to black
}

int graph::answer()
{
	return size - count;
}


int main()
{
	// get number of test cases;
	int testCases;
	string endLine;
	cin >> testCases;


	// string to hold empty line
	string empty;
	getline(cin, empty); // get first empty line after number of test cases
	getline(cin, empty); // get empty line at the beginning of first test case

	for (int i = 1; i <= testCases; i++) // run through test cases
	{
		//for maxnode
		string maxNode;
		getline(cin, maxNode);

		int size = maxNode[0] - asciiFirst;  // get number of nodes from ascii value
		size += 1; // add 1 to get actual number

		// create an object of the graph class
		graph newGraph(size);

		// read in input
		string nodeconnections;
		while (getline(cin, nodeconnections) && !nodeconnections.empty()) // read edges
		{
			// get nodes
			int edge1, edge2;
			edge1 = nodeconnections[0] - asciiFirst;
			edge1 += 1;
			edge2 = nodeconnections[1] - asciiFirst;
			edge2 += 1;

			//cout << edge1 << "->" << edge2 << endl;

			// insert into graph
			newGraph.insert(edge1, edge2);
		}

		// call depth first search and start at node 1
		newGraph.dfs(1);


		cout << newGraph.answer();

		if (i < size - 1)
			cout << endl;
	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________