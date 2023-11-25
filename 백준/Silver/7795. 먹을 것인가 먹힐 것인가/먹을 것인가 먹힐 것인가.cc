#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, A, B;
    cin >> T;
    
    for (int t=0; t<T; ++t)
    {
        cin >> A >> B;
        vector<int> av, bv;

        for (int a=0; a<A; ++a)
        {
            int tmp;
            cin >> tmp;
            av.push_back(tmp);
        }
        for (int b=0; b<B; ++b)
        {
            int tmp;
            cin >> tmp;
            bv.push_back(tmp);
        }

        sort(av.begin(), av.end());
        sort(bv.begin(), bv.end());


        int cnt=0, idx=0;
        bool isDone = false;
        for (int a=0; a<A; ++a)
        {
            while (av[a] > bv[idx])
            {
                ++idx;
                if (idx == B)
                {
                    cnt += B * (A-a);
                    isDone = true;
                    break;
                }
            }
            if (isDone) break;
            cnt += idx;
        }
        cout << cnt << endl;
    }

    return 0;
}

/*
1 1 3 7 8
1 3 6
*/