#include<iostream>
#include<math.h>
using namespace std;

int check_sqrt(int, int);

int main()
{
	int A, B;
	cin >> A >> B;

	// 4,000,000byte = 4,000MB = 4KB
	// 짝수 다 빼면 2KB
	// 근데 제곱근 까지만 검사하면 된다,, 즉 sqrt(1,000,000) = 1,000 이네. 메모리도 괜찮을듯?
	// sqrt(A) = a, a*a=A

	for (int i = A; i <= B; i++)
	{
		int a = sqrt(i);
		int res = check_sqrt(i, a);
		if (res > 0)
			cout << i << "\n";
	}

	return 0;
}


int check_sqrt(int A, int a)
{
	for (int i = 2; i <= a; i++)
	{
		if (A % i == 0)
			return 0;

		else
			continue;
	}

	if (A == 1)
		return 0;
	else 
		return A;
}