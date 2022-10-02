#include<iostream>
#include<string>
using namespace std;

int main()
{
	while (1)
	{
		string num;
		cin >> num;
		if (num == "0")	break;
		else
		{
			int len = num.size();
			//cout << "len" << len << endl;

			for (int i = 0; i <= len / 2; i++)
			{
				if (/*len % 2 == 0 && */i == len / 2)
				{
					cout << "yes" << endl;
					break;
				}
				//else if (len % 2 == 1 && i == len / 2)
				//{
				//	cout << "yes" << endl;
				//	break;
				//}
				if (num[i] != num[len - i - 1])
				{
					cout << num[i] << " " << num[len - i - 1] << endl;
					cout << "no" << endl;
					break;
				}
			}

		}
	}
	return 0;
}