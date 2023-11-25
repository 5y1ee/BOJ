#include <bits/stdc++.h>
using namespace std;

int main()
{
    // N : days, M : count of withdraw
    int N, M, tot=0, _max=0;
    cin >> N >> M;

    vector<int> v;
    for (int i=0; i<N; ++i)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        tot += tmp;
        _max = max(_max, tmp);
    }

    int l, r, m, remain, ans=tot;
    l=_max, r=tot;
    while (l<=r)
    {
        m = (l+r)/2;
        remain = m;
        int cnt=1;
        for (int i=0; i<N; ++i)
        {
            if (remain < v[i])
            {
                remain = m-v[i];
                ++cnt;
            }
            else
                remain -= v[i];
        }
        if (cnt > M)
        {
            l = m+1;
            continue;
        }
        else
            r = m-1;

        ans = min(ans, m);

    }

    cout << ans;

}