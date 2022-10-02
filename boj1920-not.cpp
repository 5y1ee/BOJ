#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class myClass
{
public:
	int N = 0, M = 0;
	vector<int> vn, vm, sol;



};
int mergeSort(myClass &C, int i, int start, int end)
{
	int mid = (start + end) / 2;

	if (C.vm[i] == C.vn[mid])
	{
		cout << "1\n";
		//C.sol.push_back(1);
		//cout << "ENDDDD\n";
		return 0;
	}

	if (mid <= start)
	{
		if (C.vm[i] == C.vn[mid])
			cout << "1\n";
			//C.sol.push_back(1);
		else
			cout << "0\n";
			//C.sol.push_back(0);

		//cout << "END\n";

		return 0;
	}

	if (C.vm[i] <= C.vn[mid])
	{
		//cout << start << " " << end << " " << C.vn[mid] << " is big..\n";
		end = mid;
		mergeSort(C, i, start, end);
		return 0;
	}
	else  // vm[i] > vn[mid]
	{
		//cout << start << " " << end << " " << C.vn[mid] << " is small..\n";
		start = mid;
		mergeSort(C, i, start, end);
		return 0;
	}
	
	return 0;
}

int main()
{
	//int N, M;
	//vector<int> vn, vm, sol;
	myClass C = myClass();

	cin >> C.N;
	for (int i = 0; i < C.N; i++)
	{
		int tmp;
		cin >> tmp;
		C.vn.push_back(tmp);
	}

	cin >> C.M;
	for (int i = 0; i < C.M; i++)
	{
		int tmp;
		cin >> tmp;
		C.vm.push_back(tmp);
	}

	sort(C.vn.begin(), C.vn.end());

	for (int i = 0; i < C.M; i++)
	{
		int len = C.sol.size();
		int start = 0, end = C.N, mid = end / 2;

		//cout << "Find " << C.vm[i] << "\n";
		mergeSort(C, i, start, end);

		/*
		if (C.vm[i] <= C.vn[mid])
		{
			for (int j = 0; j < mid; j++)
			{
				if (C.vm[i] == C.vn[j])
				{
					C.sol.push_back(1);
					mid = j;
					break;
				}
			}

			while (C.vm[i] != C.vn[mid])
			{
				end = mid;
				mid = (start + end) / 2;


			}
		}
		else
		{
			for (int k = mid; k < C.N; k++)
			{
				if (C.vm[i] == C.vn[k])
				{
					C.sol.push_back(1);
					mid = k;
					break;
				}
			}
		}
		if (len == C.sol.size())
			C.sol.push_back(0);
		*/



	}

	for (int i = 0; i < C.sol.size(); i++)
		cout << C.sol[i] << "\n";

	return 0;
}


/*
ex)

5
4 1 5 2 3
5
1 3 7 9 5

*/