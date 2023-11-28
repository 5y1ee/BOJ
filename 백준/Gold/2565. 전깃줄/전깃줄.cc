#include <bits/stdc++.h>
using namespace std;

int ans = 100;

bool check(vector<pair<int, int>>& ladder, vector<int>& v, int& N)
{
    int idx=0, prev=-1;
    bool available = true;
    for (int i=0; i<N; ++i)
    {
        if (idx<v.size() && v[idx] == i)
        {
            ++idx;
            continue;
        }
        int cur = ladder[i].second;
        if (prev >= cur)
        {
            available = false;
            break;
        }
        else
            prev = cur;
    }
    if (available)
    {
        // cout << "#";
        // for (auto i : v)
        //     cout << i << ",";
        // cout << endl;
        ans = min(ans, (int)v.size());
        return true;
    }
    else
        return false;
}

bool combi(vector<pair<int, int>>& ladder, vector<int> v, int N, int m, int idx)
{
    if (v.size() == m)
    {
        // for (auto i : v)
        //     cout << i << ",";
        // cout << endl;
        if (check(ladder, v, N)) 
        {
            return true;
        }
        else
            return false;
    }

    bool available;

    for (int i=idx+1; i<N; ++i)
    {
        v.push_back(i);
        available = combi(ladder, v, N, m, i);
        if (available) break;
        v.pop_back();
    }

    return available;
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    // 교차하지 않기 위해 없애야 하는 전깃줄의 최소 개수
    // 전깃줄의 개수 <= 100
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    for (int i=0; i<N; ++i)
    {
        int A, B;
        cin >> A >> B;
        v.push_back({A,B});
    }
    sort(v.begin(), v.end());

    int res=0;
    vector<int> dp(N, 0);
    for (int i=0; i<N; ++i)
    {
        for (int k=0; k<i; ++k)
        {
            if (v[i].second > v[k].second)
            {
                if (dp[k] >= dp[i])
                    dp[i] = dp[k] + 1;
            }
        }
        res = max(res, dp[i]);
    }
    cout << N - res - 1;
    return 0;


    int l=0, r=N-1, m;
    int cmp=100;
    while (l<=r)
    {
        m = (l+r)/2;
        combi(v, vector<int>(), N, m, -1);

        if (cmp > ans)
        {
            r = m-1;
            cmp = ans;
        }
        else
            l = m+1;
    }

    cout << ans << endl;
}