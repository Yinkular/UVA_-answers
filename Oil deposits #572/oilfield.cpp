#include <iostream>
#include <vector>

using namespace std;

void searchBlob(vector<vector <char>>, int, int); // function to search blob

int main()
{
	int row, column;
	
	cin >> row >> column;
	
	vector <vector <char>> oilField(row); // create a multi dimensional matrix
	
	//loop through oil field
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cin >> oilField[i][j];
		}
	}
	
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(oilField[i][j]=="@")
			{
				searchBlob (oilField, i, j)// pass the oilField and current position to the function
			}
		}
	}
	
	return 0;
}

void searchBlob (vector<vector<char>> oilField, int i, int j)
{
	// change current position to a sentinel value_comp
	oilField[i][j] = '-';
	
	while(oilField[i+1][j] == '@'||oilField[i][j+1] =='@'||oilField[i-1][j] == '@'||oilField[i][j-1] =='@'
	oilField[i+1][j+1]== '@'||oilField[i+1][j-1]=='@'||oilField[i-1][j-1] == '@'||oilField[i-1][j+1] =='@')
	{
		if(oilField[i+1][j] == '@')
		{
			searchBlob(oilField, i+1, j);
		}
		
		else if(oilField[i][j+1] =='@')
		{
			searchBlob(oilField, i, j+1);
		}
		
		else if(oilField[i-1][j] == '@')
		{
			searchBlob(oilField, i-1, j);
		}
		
		else if(oilField[i][j-1] =='@')
		{
			searchBlob(oilField, i, j-1);
		}
		
		else if(oilField[i+1][j+1]== '@')
		{
			searchBlob(oilField, i+1, j+1);
		}
		
		else if(oilField[i+1][j-1]=='@')
		{
			searchBlob(oilField, i+1, j-1);
		}
		
		else if(oilField[i-1][j-1] == '@')
		{
			searchBlob(oilField, i-1, j);
		}
		
		else if(oilField[i-1][j+1] =='@')
		{
			searchBlob(oilField, i-1, j+1);
		}
	}
}