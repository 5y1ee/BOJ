#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v, cnt(N, 0);
    for (int i=0; i<N; ++i)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int ans=0;
    for (int i=0; i<N; ++i)
    {
        int maxval=0;
        for (int k=0; k<i; ++k)
        {
            if (v[k] < v[i] && maxval < cnt[k])
                maxval = cnt[k];
        }
        cnt[i] = maxval+1;
        ans = max(cnt[i], ans);


        // int cnt=1, cur=v[i];
        // for (int k=i+1; k<N; ++k)
        // {
        //     if (v[k]>cur)
        //     {
        //         cur = v[k];
        //         ++cnt;
        //     }
        // }
        // ans = max(ans, cnt);
    }

    cout << ans;
}