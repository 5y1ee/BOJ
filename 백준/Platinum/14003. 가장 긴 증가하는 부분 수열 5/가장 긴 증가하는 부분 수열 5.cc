#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, ans=0, idx=0, len=0;
    cin >> N;

    vector<ll> v, cnt(N, 1e9+1);
    vector<vector<ll>> history(N, vector<ll>());
    vector<pair<int, int>> p(N);

    for (int i=0; i<N; ++i)
    {
        ll tmp;
        cin >> tmp;
        
        auto lowerPos = lower_bound(cnt.begin(), cnt.begin()+len, tmp);
        if (*lowerPos == 1e9+1)
            ++len;
        *lowerPos = tmp;
        p[i].first = lowerPos - cnt.begin();
        p[i].second = tmp;


        // v.push_back(tmp);
    }
    cout << len << endl;

    stack<int> asdf;
    for (int i=N-1; i>=0; --i)
    {
        if (p[i].first == len -1)
        {
            asdf.push(p[i].second);
            --len;
        }
    }
    while (asdf.size())
    {
        cout << asdf.top() << " ";
        asdf.pop();
    }
    return 0;


    for (int j=0; j<N; ++j)
    {
        if (cnt[j] == 1e9+1) break;
        cout << cnt[j] << " ";
    }
    cout << endl;

    return 0;

    for (int i=0; i<N; ++i)
    {
        int val=0;
        for (int j=0; j<i; ++j)
        {
            if (v[i]>v[j] && val<cnt[j])
            {
                val = cnt[j];
                history[i] = history[j];
            }
        }
        cnt[i] = val+1;
        history[i].push_back(v[i]);

        if (ans < cnt[i])
        {
            ans = cnt[i];
            idx=i;
        }
    }
    
    cout << ans << endl;
    for (auto i : history[idx])
        cout << i << " ";


}