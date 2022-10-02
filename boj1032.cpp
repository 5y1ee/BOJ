#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	char* ary[50];
	string str[50];

	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		//cout << str[i] << endl;
	}

	char sol[50];
	int sz = str[0].size();

	for (int i = 0; i < sz; i++)
	{
		char ch = str[0][i];
		for (int k = 0; k < N; k++)
		{
			if (str[k][i] == ch)
			{
				sol[i] = ch;
				continue;
			}
			else
			{
				sol[i] = '?';
				break;
			}
		}
	}
	sol[sz] = '\0';

	cout << sol << endl;

}
