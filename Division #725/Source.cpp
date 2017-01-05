#include <iostream>
#include <vector>
#include <iomanip>

#define endl "\n"


using namespace std;

typedef pair<int, int> fraction;

bool checkDifference(int numerator, int denominator)
{
	vector<bool> num(10, false); // array to store if digits already exist or not

	int remainder, count =0;

	while (denominator > 0) // loop through denominator and get digits
	{
		remainder = denominator % 10;
		if (num[remainder] == false)
		{
			num[remainder] = true;
		}

		else
		{
			return false;
		}

		denominator = denominator / 10;
		count++;
	}

	if (count < 5 && !num[0]) // if the length is less than five add a zero
	{
		num[0] = true;
	}

	else if (count < 5 && num[0]) // if it is less than five and a zero exists already
	{
		return false;
	}

	count = 0;

	remainder = 0;

	while (numerator > 0) // loop through numerator
	{
		remainder = numerator % 10;
		if (num[remainder] == false)
		{
			num[remainder] = true;
		}

		else
		{
			return false;
		}
		
		numerator = numerator / 10;
		count++;
	}

	if (count < 5 && num[0]) // if less than five and there's a zero already
	{
		return false;
	}

	return true;
}

vector<vector<fraction>> preprocess()
{
	vector<vector<fraction>> pairs(80);
	int numerator, denominator;
	bool status;

	// strat from 2 which is the lower limit to 79 upper limit
	for (int i = 2; i < 80; i++)
	{
		// start from 1234  the first number with five unique digits 01234
		// and end at 50000 which is the upper limit given by the highest numerator divided by lowest n 99999/2
		for (denominator = 1234; denominator <= 50000; denominator++) 
		{
			numerator = i * denominator;

			if (numerator > 99999) // if it's greater than 5 digits
			{
				break;
			}

			else
			{
				// check if the numbers are different
				status = checkDifference(numerator, denominator);

				if (status) // if different
				{
					pairs[i].push_back({ numerator, denominator }); // load to vector
				}
			}
		}
	}

	return pairs; // return a vector caontaing digits 2-79 and their unique numerators and denominators
}

int main()
{
	int number, count =0;
	vector<vector<fraction>> pairs = preprocess();

	while (cin >> number&& number != 0)
	{
		if (count > 0)
			cout << endl;

		if (number < 80 && pairs[number].size() != 0) // check if number is within limit and it has unique numerator and denominators
		{
			for (int i = 0; i < pairs[number].size(); i++)
			{
				cout << setfill('0') << setw(5) << pairs[number][i].first << " / " << setfill('0') << setw(5)
					<< pairs[number][i].second 	<< " = " << number <<endl;
			}
		}

		else
		{
			cout << "There are no solutions for " << number << "."<< endl;
		}
		count++;
	}
}