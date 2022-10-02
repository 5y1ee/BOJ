#include<iostream>
#include<string>
#include<vector>
using namespace std;

void merge(vector<string>& v, int start, int end, int m);
void mergeSort(vector<string>& v, int start, int end);

int main()
{
	/*
	int N;
	cin >> N;

	string* strPtr = new string[N];
	for (int i = 0; i < N; i++)
		cin >> strPtr[i];

	for (int i = 0; i < N; i++)
		cout << strPtr[i].length() << endl;


	for (int i = 0; i < N; i++)
	{

	}



	for (int i = 0; i < N; i++)
		cout << strPtr[i] << endl;
	*/
	// merge sort
	int n;
	cin >> n;
	vector<string> vec(n);

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		vec[i] = tmp;
		//vec.push_back(tmp) 이러면 ""공백 뒤에 들어가서 의도한대로 안된다.
	}

	//cout << "len : " << vec.size() << endl;
	//cout << vec[n - 1] << endl;

	mergeSort(vec, 0, n - 1);


	for (int i = 0; i < n; i++)
	{
		if (i > 0 && vec[i] == vec[i - 1])
			continue;
		cout << vec[i] << endl;
	}

}

void merge(vector<string>& v, int start, int end, int mid)
{
	vector<string> res;
	int i = start;
	int j = mid + 1, copy = 0;
	int idx = 0;

	while (i <= mid && j <= end)
	{
		char chi = v[i][idx], chj = v[j][idx];
		cout << "--" << v[i] << " " << v[j] << "--" << endl;

		if (v[i] == v[j]) {
			cout << v[i] << " == " << v[j] << endl;
			res.push_back(v[i++]);
			res.push_back(v[j++]);
			idx = 0;
		}
		//if(v[i]!=v[j])
		else
		{
			if (v[i].size() < v[j].size()) { res.push_back(v[i++]); idx = 0; }
			else if (v[i].size() > v[j].size()) { res.push_back(v[j++]); idx = 0; }
			else if (chi < chj) { res.push_back(v[i++]); idx = 0; }
			else if (chi > chj) { res.push_back(v[j++]); idx = 0; }
			else idx++;
		}

		//if (i != start || j != mid + 1)	idx = 0;

		cout << "i : " << i << ", j :" << j << ", start :" << start << ", mid :" << mid << ", end :" << end << endl << "vector -> ";
		for (int k = 0; k <= end; k++)
			cout << v[k] << " ";
		cout << endl;
	}

	while (i <= mid)	res.push_back(v[i++]);
	while (j <= end)	res.push_back(v[j++]);

	for (int x = start; x <= end; x++)
		v[x] = res[copy++];

	for (int i=0;i<=end;i++)
		cout << v[i] << " ";
	cout << "\n\n";

}
void mergeSort(vector<string>& v, int start, int end)
{
	if (start < end)	// n < n break..
	{
		int mid = (start + end) / 2;

		mergeSort(v, start, mid);
		mergeSort(v, mid + 1, end);

		merge(v, start, end, mid);
	}
}
