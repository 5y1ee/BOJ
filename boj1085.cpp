#include<iostream>
using namespace std;

int main()
{
	int x, y, w, h, res;
	cin >> x >> y >> w >> h;

	if (x <= w / 2)	w = 0;
	if (y <= h / 2)	h = 0;
	res = abs(w - x) < abs(h - y) ? abs(w - x) : abs(h - y);
	cout << res;
}