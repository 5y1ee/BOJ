#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, ans=0, idx=0;
    cin >> N;

    vector<int> v, cnt(N, 0);
    vector<vector<int>> history(N, vector<int>());

    for (int i=0; i<N; ++i)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

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