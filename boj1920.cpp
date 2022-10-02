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
int mergeSort(myClass* C, int i, int start, int end)
{
	int mid = (start + end) / 2;

	if (C->vm[i] == C->vn[mid])
	{
		C->sol.push_back(1);
		return 0;
	}

	if (mid <= start)
	{
		if (C->vm[i] == C->vn[mid])
			C->sol.push_back(1);
		else
			C->sol.push_back(0);

		return 0;
	}

	if (C->vm[i] <= C->vn[mid])
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
		int start = 0, end = C.N;

		mergeSort(&C, i, start, end);
	}

	for (int i = 0; i < C.sol.size(); i++)
		cout << C.sol[i] << "\n";

	return 0;
}