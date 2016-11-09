//**************************************************************
//                   Project: #20 Oil Deposits
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 11/1/2016
//***************************************************************
//   	Program searches for number of connected oil blocks in an
//		oil field.
//
//      Input format -> contains a grid of oildfield with oilblocks 
//						marked with '@' and '*' if otherwise.
//      Output Format -> Number of contiguous oilfields.
//*****************************************************************
// Program Complexity -> O(n^2)
//*****************************************************************

#include <iostream>
#include <vector>

using namespace std;

void searchBlob(vector<vector <char>>&, int, int); // function to search blob

int main()
{
	int row, column;

	while (cin >> row >> column && row != 0)
	{
		int count = 0;
		vector <vector <char>> oilField(row, vector<char>(column)); // create a multi dimensional matrix

		//insert into matrix
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cin >> oilField[i][j];
			}
		}

		// check for oil blocks
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (oilField[i][j] == '@')
				{
					searchBlob(oilField, i, j);// pass the oilField and current position to the function
					count++;
				}
			}
		}

		cout << count << endl;
	
	}
	return 0;
}

// vector is passed by reference
void searchBlob(vector<vector<char>> &oilField, int i, int j)
{
	// if we exceed field size or hit a non oil spot return
	if (i<0 || j< 0 || i> oilField.size() - 1 || j> oilField[0].size() - 1 || oilField[i][j] != '@')
	{
		return;
	}

	oilField[i][j] = '*'; // replace current spot with a '*'

	// recursive search
	searchBlob(oilField, i - 1, j - 1);
	searchBlob(oilField, i - 1, j);
	searchBlob(oilField, i - 1, j+1);
	searchBlob(oilField, i, j - 1);
	searchBlob(oilField, i, j + 1);
	searchBlob(oilField, i + 1, j - 1);
	searchBlob(oilField, i + 1, j);
	searchBlob(oilField, i + 1, j + 1);

}


// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________