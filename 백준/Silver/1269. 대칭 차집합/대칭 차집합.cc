#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    vector<int> av, bv;
    for (int i=0; i<A; ++i)
    {
        int tmp;
        cin >> tmp;
        av.push_back(tmp);
    }
    for (int i=0; i<B; ++i)
    {
        int tmp;
        cin >> tmp;
        bv.push_back(tmp);
    }
    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());
    int cnt=0;
    // A의 값이 B에 있는지 이분탐색
    for (int i=0; i<A; ++i)
    {
        int l=0, r=B-1, m, val=av[i];
        while (l<=r)
        {
            m = (l+r)/2;

            if (val == bv[m])
            {
                ++cnt;
                break;
            }
            
            if (val > bv[m])
                l = m+1;
            else
                r = m-1;
        }
    }

    cout << A + B - cnt * 2;
}