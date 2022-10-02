#include<iostream>
#include<cmath>
using namespace std;

int f(int N);

int main()
{
	int N, sol = 666;
	cin >> N;

	//cout << f(N);

	while (1)
	{
		if (f(sol) == 1)
		{
			N--;
			if (N == 0)
			{
				cout << sol << endl;
				break;
			}
		}
		sol++;
	}
	return 0;
}

int f(int N)
{
	int len = 0, tmp = N, stack = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}

	for (int i = 0; i < len; i++)
	{
		tmp = N % (int)pow(10, i + 1);
		tmp = tmp / int(pow(10, i));

		if (tmp == 6)	stack++;
		else if (tmp != 6)	stack = 0;

		if (stack == 3)	return 1;
	}

	return 0;
}