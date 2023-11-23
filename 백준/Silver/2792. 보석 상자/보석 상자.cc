#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    long long N, M, Max=0, Min = LLONG_MAX;
    cin >> N >> M;
    vector<long long> v;
    for(int i=0; i<M; ++i)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
        Max = max(Max, tmp);
    }

    long long num, l, r, m;
    l=1, r=Max;

    while (l<=r)
    {
        m=(l+r)/2;
        num = N;

        for (int i=0; i<M; ++i)
        {
            // num -= (v[i] / m + 1);
            // if (v[i] % m == 0)
            //     num += 1;
            num -= (v[i]/m);
            if (v[i] % m != 0)
                num -= 1;
        }        
        if (num >= 0){
            Min = min(Min, m);
            r = m-1;
        }        
        else
            l = m+1;
    }

    cout << Min;    
}