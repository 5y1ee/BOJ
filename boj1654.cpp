#include<iostream>
#include<vector>
using namespace std;

int func(int, int);

int N, K;
vector<int> v;

int main()
{
	// N : �ʿ��� ����(�鸸), K ���� �ִ� ����(��)
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int max = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (max < v[i])	max = v[i];
	}
	
	//int sol = func(1, max);

	int sol = 0;

	long long mid;
	int min = 1;

	while (min <= max)
	{
		int num = 0;
		mid = (min + max) / 2;
		for (int i = 0; i < v.size(); i++)
			num += v[i] / mid;

		//cout << num << "-> max: " << max << ", mid: " << mid << ", min: " << min << endl;

		//if (num < N)	// mid ���̱�
		//{
		//	max = mid - 1;
		//}
		//else/* if (num > N)*/
		//{
		//	if (sol < mid) sol = mid;
		//	min = mid+1;
		//}
		//else if (num == N)
		//{
		//	sol = mid;
		//	break;
		//}

		if (num >= N)
		{
			max = mid + 1;
			if (mid > max)max = mid;
		}
		else
		{
			min = mid - 1;
		}

	}

	cout << max;

	return 0;
}

int func(int min, int max)
{
	int num = 0, a;
	long long mid;
	mid = (min + max) / 2;

	for (int i = 0; i < v.size(); i++)
		num += v[i] / mid;

	cout << num << "-> max: " << max << ", mid: " << mid << ", min: " << min << endl;
	cin >> a;

	if (num < N)	// �ʿ��� �������� ���� ���� (���̸� �ٿ�����)
	{
		max = mid-1;
		mid = func(min, max);
	}
	else if (num > N) // �ʿ��� ���� �̻����� ���� (���̸� �÷�����)
	{
		min = mid+1;
		mid = func(min, max);
	}
	else if (num == N)	// ���⼱ �ִ븦 ���ؾ���..
	{
		while (1)
		{
			num = 0;
			for (int i = 0; i < v.size(); i++)
				num += v[i] / mid;
			cout << num << " " << mid << endl;
			if (num != N) { mid--; break; }
			else mid++;
		}
		return mid;
	}

	return mid;
}