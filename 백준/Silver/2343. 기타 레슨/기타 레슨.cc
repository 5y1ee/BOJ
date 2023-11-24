#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, _max=0;
    cin >> N >> M;

    long long tot=0, ans=LLONG_MAX;
    vector<int> v;
    for (int i=0; i<N; ++i)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        tot += tmp;
        _max = max(_max, tmp);
    }

    long long l, r, m;
    // l=_max, r=tot/(M-1);
    l=_max, r=tot;

    while (l<=r)
    {
        m=(l+r)/2;
        long long sum=0, _size=0;
        int track=0, i;
        for (i=0; i<N; ++i)
        {
            sum+=v[i];
            if (sum >= m)
            {
                ++track;
                if (track > M)
                    break;
                
                // sum > m
                if (sum-m!=0)
                {
                    sum -= v[i];
                    --i;
                }
                // _size = max(_size, sum);
                sum=0;
            }
            
        }

        if (sum != 0)
        {
            ++track;
            // _size = max(_size, sum);
        }

        if (track > M)
        {
            l = m+1;
            continue;
        }

        if (i==N && track==M)
        {
            ans = min(ans, m);
            r = m-1;
        }
        else if (track < M)
        {
            r = m-1;
        }

    }
    if (ans == LLONG_MAX) ans = m;
    cout << ans;
    // cout << m;

}