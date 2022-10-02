#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(vector<int> &, int);
int get_Max(vector<int> &);

int main()
{
	int N;
	cin >> N;
	vector<int> sol;
	for (int i = 0; i < N; i++)
	{
		vector<int> v;
		int num, idx, tmp;
		cin >> num >> idx;

		for (int i = 0; i < num; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
		}
		int res = func(v, idx);
		sol.push_back(res);
	}

	int sz = sol.size();
	for (int i = 0; i < sz; i++)
		cout << sol[i] << "\n";

	return 0;
}

int func(vector<int> &v, int idx)
{
	int sz = v.size(), max = 0, res = 1, i = 0, des = v[idx];
	while(v.size())
	{
		max = get_Max(v);
		//cout << "max of this loop : " << max << ", v[0] : " << v[0] << "\n";

		if (max == v[0])
		{
			if (idx == 0)
			{
				//cout << "break\n";
				break;
			}

			v.erase(v.begin());
			res++;
			idx--;
		}

		else
		{
			//i++;
			if (v.size() > 0)
			{
				v.push_back(v[0]);
				v.erase(v.begin());
			}

			if (idx > 0)
				idx--;
			else
				idx = v.size() - 1;
		}


	}

	return res;


	/*
	for (int i = idx + 1; i < num; i++)
	{
		if (v[i] == v[idx])
			cnt++;
		else
			;
	}
	//cout << cnt << "\n";
	sort(v.begin(), v.end());

	int sz = v.size(), sol = -99;
	for (int i = sz - 1; i >= 0; i--)
	{
		if (v[i] == v[idx])
		{
			sol = sz - i;
			cout << "cnt : " << cnt;
			cout << " sol : " << sol << "\n";
			break;
		}
	}

	return sol;
	*/

}

int get_Max(vector<int> &v)
{
	int sz = v.size(), max = 0;
	for (int i = 0; i < sz; i++)
	{
		if (max < v[i])
			max = v[i];
	}
	return max;
}


/*
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1
*/




/*

1 2 5 4 3 2 5 4 1 3
2 5 4 3 2 5 4 1 3 1
5 4 3 2 5 4 1 3 1 2 @
4 3 2 5 4 1 3 1 2
3 2 5 4 1 3 1 2 4
2 5 4 1 3 1 2 4 3
5 4 1 3 1 2 4 3 2 @
4 1 3 1 2 4 3 2 @
1 3 1 2 4 3 2
3 1 2 4 3 2 1
1 2 4 3 2 1 3
2 4 3 2 1 3 1
4 3 2 1 3 1 2 @
3 2 1 3 1 2 @
2 1 3 1 2
1 3 1 2 2
3 1 2 2 1 @
1 2 2 1
2 2 1 1 @
2 1 1 @
1 1 @
1 @
.







5 5 4 4 3 3 2 2 1 1



*/