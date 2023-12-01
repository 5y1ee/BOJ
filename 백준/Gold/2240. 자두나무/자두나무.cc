#include <bits/stdc++.h>
using namespace std;

#define time int
#define move int
#define location int

int T, W;

// dp[time][move][location]
void func(vector<vector<vector<int>>>& dp, vector<int>& v, int t, int m, int l)
{
    // 움직일 수 있는 횟수를 넘은 경우, return
    // 시간 지나면 return
    if (m > W || t == T) return;
    if (dp[t][m][l] == -1) dp[t][m][l] = 0;

    // 해당 time에 떨어지는 자두의 위치
    int val = v[t]-1;

    // 현재 위치한 곳에 자두가 떨어진다면,
    if (val == l)
    {
        ++dp[t][m][l];
        if (dp[t+1][m][l] > dp[t][m][l]) return;
        dp[t+1][m][l] = dp[t][m][l];
        func(dp, v, t+1, m, l);
    }
    // 현재 위치한 곳에 자두가 떨어지지 않는 경우,
    else
    {
        // 움직이지 않는 경우
        if (dp[t+1][m][l] <= dp[t][m][l])
        {
            dp[t+1][m][l] = dp[t][m][l];
            func(dp, v, t+1, m, l);
        }

        // 위치를 옮길 수 있는 경우
        if (m+1 <= W)
        {
            if (dp[t][m+1][val] <= dp[t][m][l] + 1)
            {
                dp[t][m+1][val] = dp[t][m][l] + 1;
                dp[t+1][m+1][val] = dp[t][m+1][val];
                func(dp, v, t+1, m+1, val);
            }
        }
    }

}

int main()
{
    // 매 초, 두 나무 중 하나의 나무에서 열매가 떨어진다. 떨어질 때 그 나무 아래에 있으면 열매를 획득할 수 있다.
    // T초 동안 지속, 최대 W번 움직일 수 있다.
    cin >> T >> W;
    vector<int> v(T);
    for(int i=0; i<T; ++i)
    {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
    }
    
    vector<vector<vector<time>>> dp(T+1, vector<vector<move>>(W+1, vector<location>(2, -1)));
    // cout << dp.size() << endl;
    // cout << dp[0].size() << endl;
    // cout << dp[0][0].size() << endl;

    func(dp, v, 0, 0, 0);

    // for (int t=0; t<T; ++t)
    // {
    //     cout << "time " << t << ", " << v[t] << endl;
    //     for (int m=0; m<W+1; ++m)
    //     {
    //         for (int l=0; l<2; ++l)
    //             cout << dp[t][m][l] << ", ";
    //         cout << endl;
    //     }
    //     cout << "========\n\n";
    // }

    int ans=0;
    for (int m=0; m<W+1; ++m)
    {
        for (int l=0; l<2; ++l)
        {
            ans = max(dp[T-1][m][l], ans);
        }
    }
    cout << ans;

}