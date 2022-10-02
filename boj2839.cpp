// Dynamic Programming - silver4
#include<iostream>
using namespace std;

int func(int N);
int fun(int N);
int ary[5001] = { };

int main()
{
	int N;
	cin >> N;
	
	cout << "sol : " << fun(N) << endl;

	//for(int i=0;i<=N;i++)
	//	cout << ary[i] << " ";

	return 0;
}

int func(int N)
{
	if (ary[N] != 0) return ary[N];
	cout << N << endl;
	int tmp = 9999;

	if (N < 3)
	{
		ary[N] = -1;
		return ary[N];
	}
	else if (1)	// 3, 5 multi check
	{
		if (N % 5 == 0)
			return N / 5;
		if (N % 3 == 0)
		{
			tmp = (N / 3) < tmp ? (N / 3) : tmp;
			//return N / 3;
		}
	}

	if (N > 3)
		ary[N] = func(N - 3) + 1 < tmp ? func(N - 3) + 1 : tmp;

	if (tmp == 9999)
	{
		ary[N] = -1;
		tmp = -1;
	}

	return ary[N];
}


int fun(int N)
{
	if (ary[N] != 0) return ary[N];
	//if (N == 3) return 1;
	int tmp;
	if (N < 3)
	{
		ary[N] = -1;
		return ary[N];
	}
	else if (N % 5 == 0)
		return ary[N] = N / 5;
	else if (N % 3 == 0)
	{
		tmp = N / 3;
		if (N > 3)
			ary[N] = fun(N - 3) + 1 < tmp ? fun(N - 3) + 1 : tmp;
		else ary[N] = tmp;
	}
	else
	{
		int bf = fun(N - 3);
		if (bf > 0)	ary[N] = bf + 1;
		else
			return -1;
	}


	return ary[N];
}