#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

#define MAXSIZE 100
unsigned long answer[MAXSIZE];

unsigned long long int power(unsigned long base, unsigned long exp)
{
	unsigned long long int result = 1;
	while (exp)
	{
		if (exp & 0x01)
			result *= base;
		base *= base;
		exp >>= 1;
	}

	return result;
}

unsigned long cn2(unsigned long n)
{
	unsigned long x = (1 << n) + 1;
	unsigned long mask = (1 << n) - 1;

	return (power(x, n) >> ((n >> 1) * n)) & mask;
}

unsigned long factorial(unsigned long n)
{
	unsigned long temp;

	if (n == 1)
		return 1;
	else if (n & 0x01 == 1)
		return n * factorial(n - 1);
	else
	{
		temp = factorial(n >> 1);
		return cn2(n) * temp * temp;
	}
}

int main()
{
	int number = 10000;
	unsigned long result = factorial(number);
	cout << "result = " << result << endl;
	return 0;
}
