#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	bool isCompatible = true;
	stack<int> s;
	vector<int> v;
	vector<char> c;
	int n, val = 1, idx = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	while (true)
	{
		if (idx == n)	break;

		if (v[idx] >= val)	// v = [4 3 6 8 7 5 2 1], idx = 0~7, val = 1~8
		{
			s.push(val++);
			//cout << "+" << endl;
			c.push_back('+');
		}
		else if (v[idx] < val)	// v = [4 3 ...], idx=4 -> v[]=
		{
			if (s.top() == v[idx])
			{
				s.pop();
				//cout << "-" << endl;
				c.push_back('-');
				idx++;
			}
			else
			{
				isCompatible = false;
				break;
			}
		}

	}

	if (isCompatible)
	{
		for (int i = 0; i < c.size(); i++)
		{
			cout << c[i];
			cout << "\n";
		}
	}
	else
		cout << "NO";

	return 0;
}