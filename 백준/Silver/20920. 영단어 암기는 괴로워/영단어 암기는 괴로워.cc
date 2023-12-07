#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        if (a.first.size() == b.first.size())
            return a.first < b.first;
        else
            return a.first.size() > b.first.size();
    }
    else
        return a.second > b.second;

    // return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    // 단어의 개수, 길이 기준
    // 자주 나오는 단어 -> 단어의 길이가 긴 단어 -> 알파벳 사전 순    
    string str;
    map<string, int> v;
    for(int i=0; i<N; ++i)
    {
        cin >> str;
        if (str.size() < M) continue;

        if (v.count(str) == 0)
            v.insert({str, 1});
        else
            ++v[str];            
    }
    vector<pair<string, int>> vec(v.begin(), v.end());

    sort(vec.begin(), vec.end(), cmp);

    for (auto i : vec)
        cout << i.first << "\n";

}