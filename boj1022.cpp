#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int c1, c2, r1, r2;
	cin >> r1 >> c1 >> r2 >> c2;

	 //(-n,-n+1) == 2n^2 Â¦¼ö Á¦°ö
	 //(n,n) == (2n+1)^2 È¦¼ö Á¦°ö

	int row = r2 - r1;
	int col = c2 - c1;
	int max = 0;
	int ary[50][5];

	for (int r = 0; r <= row; r++)	// ~50
	{
		for (int c = 0; c <= col; c++) // ~5
		{

			if (r + r1 <= 0)	// »ó
			{
				if (abs(r + r1) >= abs(c + c1))	// y=|x| ÀÇ »ó(Áß°£)
				{
					ary[r][c] = pow(abs(2 * (r + r1)), 2) + 1 - (c + c1) + (r + r1);
					max = ary[r][c] > max ? ary[r][c] : max;
				}
				else if ((r + r1) > (c + c1))	// y=-x ÀÇ »ó(ÁÂ)
				{
					ary[r][c] = pow(2 * (c + c1), 2) + (r + r1) - (c + c1) + 1;
					max = ary[r][c] > max ? ary[r][c] : max;
				}
				else if ((r + r1) < (c + c1))	// y=x ÀÇ »ó(¿ì)
				{
					ary[r][c] = pow(abs(2 * (c + c1)) - 1, 2) + abs(c + c1 - 1) + 1 - (r + r1);
					max = ary[r][c] > max ? ary[r][c] : max;
				}
			}
			else if (r + r1 > 0)	// ÇÏ
			{
				if ((r + r1) >= abs(c + c1))	// y=|x| ÀÇ ÇÏ(Áß°£)
				{
					ary[r][c] = pow(abs(2 * (r + r1)+1), 2) - (r+r1)+(c+c1);
					max = ary[r][c] > max ? ary[r][c] : max;
				}
				else if ((r + r1) > (c + c1))	// y=x ÀÇ ÇÏ(ÁÂ)
				{
					ary[r][c] = pow(2 * (c + c1), 2) + (r + r1) - (c + c1) + 1;
					max = ary[r][c] > max ? ary[r][c] : max;
				}
				else if ((r + r1) < (c + c1))	// y=-x ÀÇ ÇÏ(¿ì)
				{
					ary[r][c] = pow(abs(2 * (c + c1)) - 1, 2) + abs(c + c1 - 1) + 1 - (r + r1);
					max = ary[r][c] > max ? ary[r][c] : max;
				}
			}

			//cout.width(4);
			//cout << ary[r][c] << " ";
		}
		//cout << endl;

	}
	//cout << "max : " << max << endl;

	int n = 0;
	while (1)
	{
		if (max == 0)
			break;
		else
		{
			max /= 10;
			n++;
		}
	}
	//cout << "n : " << n << endl;

	for (int r = 0; r <= row; r++)
	{
		for (int c = 0; c <= col; c++)
		{
			cout.width(n);
			cout << ary[r][c] << " ";
		}
		cout << endl;
	}

}
