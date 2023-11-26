#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X, Y, Z, l, r, m, W;
    cin >> X >> Y;
    Z = 100*Y/X;

    l = 1, r = 1e9;
    long long ans=LLONG_MAX;
    while (l<=r)
    {
        m = (l+r)/2;
        W = 100*(Y+m) / (X+m);

        if (W > Z)
        {
            r = m-1;
            ans = min(ans, m);
        }
        else
            l = m+1;

    }

    if (ans == LLONG_MAX)
        cout << -1;
    else
        cout << ans;


    
    /*
    Z = Y/X
    Y+i/X+i > Z
    */



}