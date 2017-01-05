#include <iostream>
#include <cmath>

int main()
{
	int number,sum;

	while (std::cin >> number && number != 0)
	{
		sum = 0;

		for (int i = number; i > 0; i--)
		{
			sum += (int)pow(i, 2);
		}

		std::cout << sum << std::endl;
	}
}