#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& vn, int target, int start, int end)
{
    int l, m, r;
    l = start;
    r = end;
    m = (l+r)/2;

    while (l<=r)
    {
        m = (l+r)/2;
        if (vn[m] == target)
            return 1;
        
        if (vn[m] < target)
            l = m+1;
        else if (vn[m] > target)
            r = m-1;
    }
    return 0;

    // ================Recursive================

    // if (start > end) return 0;
    int mid = (start + end) / 2;
    if (vn[mid] == target)
        return 1;
    else if (mid >= end)
        return 0;
    
    if (vn[mid] < target)
        return binary_search(vn, target, mid + 1, end);
    else
        return binary_search(vn, target, start, mid - 1);

}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T, N, M;
    cin >> T;

    for (int t=0; t<T; ++ t)
    {
        cin >> N;
        vector<int> vn, vm;
        for (int i=0; i<N; ++i)
        {
            int tmp;
            cin >> tmp;
            vn.push_back(tmp);
        }
        sort(vn.begin(), vn.end());
        
        cin >> M;
        for (int i=0; i<M; ++i)
        {
            int tmp;
            cin >> tmp;
            vm.push_back(tmp);
        }


        for (int i=0; i<M; ++i)
        {
            int val = binary_search(vn, vm[i], 0, N-1);
            cout << val << "\n";
        }

    }


}