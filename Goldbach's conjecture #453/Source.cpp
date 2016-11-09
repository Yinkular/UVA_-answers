//**************************************************************
//                   Project: #16 Goldbach’s Conjecture
//                    Name: Olayinka Soyinka
//                    Programming Techniques: 10/20/2016
//***************************************************************
//   	Program prints two prime numbers that sum up to a corresponding
//		given integer.
//
//      Input format -> Each test case consists of one even integern
//		with 6n<1000000.Input will be terminated by a value of 0 for n.
//      Output Format -> Two prime numbers that sum gives given integer
//*****************************************************************
// Program Complexity -> O(n)
//*****************************************************************


#include <iostream>
#include <vector>
#include <cmath>



using namespace std;

int main()
{
	// preprocess all primes from 1 to 1,000,000

	int start = 2, limit = 1000001;

	//create a vector of 1000000 and set the value to true helps to seive prime from non prime
	vector<bool> sieve(limit, true);

	// create a vector to store primes
	vector<int> primes;

	//loop till squareroot of number
	for (int i = start; i < sqrt(limit); i++)
	{
		if (sieve[i])
		{
			// to enter this block it i is a prime so insert to primes vector
			primes.push_back(i);

			//loop through multiples of current number excluding the number itself
			for (int j = i + i; j < limit; j += i)
			{
				// set multiples to false
				sieve[j] = false;
			}
			// end of if(primes[i])
		}

		// end of for
	}


	// solve the problem
	int number, a=0, b=0, diff;

	// accept inpuit tell there's a zero
	while (cin >> number && number != 0)
	{
		start = 0;

		// run a loop 
		while (true)
		{
			// get the difference between input and the prime
			diff = number - primes[start];

			// if the difference is a prime
			if (sieve[diff])
			{
				// set answers
				a = primes[start];
				b = diff;
				break;
			}

			start++;
		}

		cout << number << " = " << a << " + " << b << endl;

	}

	return 0;
}

// I have written the entire program as turned in and have not copied this code, 
// or parts of this code from the internet or another student.
//
// Signature ___________________