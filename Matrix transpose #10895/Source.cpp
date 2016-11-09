//**************************************************************
//                   Project: #17 Matrix Transpose
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 10/20/2016
//***************************************************************
//      The program transposes a matrix including zero elements
//		and transposes the matrix.
//
//      Input format -> Text file containing sets of matrixes 
//      Output Format -> The transpose matrix.
//*****************************************************************
// Program Complexity -> O(n^2)
//*****************************************************************


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// variable sfor and row and columns
	int row, column;
	// accept values for row and columns
	while (cin >> row >> column)
	{

		// create adjacency list to store values in each row and their respective columns
		vector <vector<pair<int, int>>> adjacencyList(row), transposeAdjacent(column);

		// variable for number of non zeros on each line
		int nonZeros;


		int currentIndex, currentValue;

		// run a loop to get values
		for (int i = 0; i < row; i++)
		{
			// vectors to store indexes and corresponding values
			vector<int> index;
			vector<int> value;

			cin >> nonZeros;

			// accept indexes
			for (int j = 0; j < nonZeros; j++)
			{
				cin >> currentIndex;
				index.push_back(currentIndex);
			}

			// accept corresponding values
			for (int j = 0; j < nonZeros; j++)
			{
				cin >> currentValue;
				value.push_back(currentValue);
			}


			// run a loop to make pairs of indexes and values
			// each vector index stores a complete row
			for (int j = 0; j < nonZeros; j++)
			{
				currentIndex = index[j] - 1; // ensure it conforms to array subscripting
				currentValue = value[j];

				adjacencyList[i].push_back(make_pair(currentIndex, currentValue));
			}
		}

		pair<int, int> value;

		// create transpose matrix
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < adjacencyList[i].size(); j++)
			{
				// get current pair 
				value = adjacencyList[i][j];

				// use column value to position i proper row
				transposeAdjacent[value.first].push_back(make_pair(i, value.second));
			}
		}

		cout << column << " " << row << endl;

		for (int i = 0; i < column; i++)
		{
			// print out size of current row
			cout << transposeAdjacent[i].size();

			// print out index of each row
			for (int j = 0; j < transposeAdjacent[i].size(); j++)
			{
				cout << " "<< transposeAdjacent[i][j].first + 1; // +1 converts back to original indexing
			}

			cout << endl;

			// print out values for each index
			for (int j = 0; j < transposeAdjacent[i].size(); j++)
			{
				cout << transposeAdjacent[i][j].second;

				if (j < transposeAdjacent[i].size() - 1)
				{
					cout << " ";
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