#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 산성 1~10억, 알칼리 -1~-10억    
    // 합이 0에 가까운 용액을 찾아라

    int N;
    cin >> N;
    vector<long long> v;
    for (int i=0; i<N; ++i)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);        
    }

    sort(v.begin(), v.end());

    long long ans = LLONG_MAX, sum, prev=ans;
    int l=0, r=N-1, L, R;
    while(l<r)
    {
        // cout << l << "," << r << endl;
        sum = v[l] + v[r];
        
        if (abs(ans) > abs(sum))
        {
            ans = sum;
            L = l, R = r;
            // ++l;
        }
        // else
        //     --r;

        if (sum == 0)
            break;
        else if (sum > 0)
        {
            --r;
        }
        else
            ++l;

        // cout << sum << "," << ans << endl;
    }
    // if (abs(ans) > abs(v[0]+v[1]))
    // {
    //     cout << v[0] << " " << v[1];
    // }
    // else
        cout << v[L] << " " << v[R];


}