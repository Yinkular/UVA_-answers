#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int number, sum=0, maxAverage =0;
	float average;

	vector<int> numbers;

	while ((cin >> number))
	{
		if (number == 0)
		{
			break;
		}

		numbers.push_back(number);
	}

	int length = numbers.size();

	for (int i = 0; i < length; i++)
	{
		sum += numbers[i];
	}

	average = sum / length;

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] > maxAverage && numbers[i] < average)
		{
			maxAverage = numbers[i];
		}
	}

	cout  << average << "==>" << maxAverage << endl;
}