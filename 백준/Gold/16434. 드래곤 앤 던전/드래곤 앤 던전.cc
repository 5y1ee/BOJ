#include <bits/stdc++.h>
using namespace std;

struct Object {
    long long type, atk, hp;
};

bool check(vector<Object> v, long long hp, long long atk)
{
    int cnt = v.size();
    long long max_Hp = hp;
    bool isPossible = true;
    for (int i=0; i<cnt; ++i)
    {
        // monster
        if (v[i].type == 1)
        {
            v[i].hp -= atk;
            if (v[i].hp <= 0)
                continue;
            else
            {
                long long X, Y;
                X = hp / v[i].atk;
                if (hp % v[i].atk != 0)
                    ++X;

                Y = v[i].hp / atk;
                if (v[i].hp % atk != 0)
                    ++Y;

                if (X <= Y || hp < 0)
                {
                    isPossible = false;
                    break;
                }
                else
                {
                    hp -= v[i].atk * Y;
                }

                // while (v[i].hp > 0 && hp > 0)
                // {
                //     hp -= v[i].atk;
                //     v[i].hp -= atk;
                // }
                // if (hp <= 0)
                // {
                //     isPossible = false;
                //     break;
                // }
                
            }
        }
        // potion
        else if (v[i].type == 2)
        {
            atk += v[i].atk;
            hp += v[i].hp;
            hp = min(max_Hp, hp);
        }

    }
    return isPossible;
}

int main()
{
    long long N, atk, t, a, h;
    cin >> N >> atk;
    vector<Object> v;
    for (int i=0; i<N; ++i)
    {
        cin >> t >> a >> h;
        v.push_back({t, a, h});
    }

    // t : 1 monster, 2 : potion
    long long l=1, r=LLONG_MAX - 1, m, ans=r;
    while (l<=r)
    {
        m = (l+r)/2;

        if (check(v, m, atk))
        {
            r=m-1;
            ans = min(ans, m);
        }
        else
            l=m+1;

    }
    cout << ans;

}

/*
atk : 3

mon : atk 1 , hp 20
pot : atk 3 , hp 10
mon : atk 3 , hp 100


*/