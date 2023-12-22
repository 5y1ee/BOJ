#include <bits/stdc++.h>
using namespace std;

int func(string s, int len)
{
    int _size = s.size(), cnt=1;
    string fr, rear, ret;
    for (int i=0; i<len; ++i)    
        fr += s[i];


    for (int i=len; i<_size; i+=len)
    {
        rear = "";
        for (int k=i; k<i+len; ++k)
        {
            if (k >= _size)
                break;
            rear += s[k];            
        }

        if (fr == rear)
            ++cnt;
        else
        {
            if (cnt > 1)
                ret += to_string(cnt);
            ret += fr;

            cnt = 1;
            fr = rear;
        }

    }
    if (cnt > 1)
        ret += to_string(cnt);
    if (fr != "")
        ret += fr;

    // cout << "len " << len << " " << ret << " " << ret.size() << endl;
    return ret.size();
}

int solution(string s) {
    int answer = INT_MAX;
    int _size = s.size()/2;
    
    if (s.size() == 1)
        return 1;

    for (int i=1; i<=_size; ++i)
    {
        int ret = func(s, i);
        answer = min(answer, ret);
    }

    return answer;
}