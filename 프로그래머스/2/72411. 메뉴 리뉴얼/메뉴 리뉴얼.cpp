#include <bits/stdc++.h>
using namespace std;

void func(map<string, int>& Map, vector<char>& order, int _len, string str, int idx)
{
    if (str.size() == _len)
    {
        // for (auto i : order)
        //     cout << i;
        // cout << "#" << str << endl;
        sort(str.begin(), str.end());
        if (Map.count(str) > 0)
            ++Map[str];
        else
            Map[str] = 1;
        return;
    }
    
    int o_cnt = order.size();
    for (int i=idx; i<o_cnt; ++i)
    {
        str += order[i];
        func(Map, order, _len, str, i+1);
        str = str.substr(0, str.size()-1);
        // cout << "$" << str << endl;
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int o_cnt = orders.size(), c_cnt = course.size();
    vector<vector<char>> order(o_cnt, vector<char>());
    
    for (int i=0; i<o_cnt; ++i)
    {
        for (int k=0; k<orders[i].size(); ++k)
            order[i].push_back(orders[i][k]);
    }
    
    for (int i=0; i<c_cnt; ++i)
    {
        int _len = course[i];
        map<string, int> Map;
        for (int idx=0; idx<o_cnt; ++idx)
        {
            if (order[idx].size() < _len) continue;
            string str="";
            func(Map, order[idx], _len, str, 0);
        }
        int _max=0;
        vector<string> tmp;
        for (auto i : Map)
        {
            cout << i.first << " " << i.second << ", ";
            if (_max < i.second)
            {
                _max = i.second;
                tmp.clear();
                tmp.push_back(i.first);
            }
            else if (_max == i.second)
                tmp.push_back(i.first);
        }
        if (_max >= 2)
        {
            for (int i=0; i<tmp.size(); ++i)
                answer.push_back(tmp[i]);
        }
        cout << endl;
        
    }
    
    
    sort(answer.begin(), answer.end());    
    return answer;
}

/*

orders <= 20
orders[0] <= 10
course <= 10
course[0] <= 10

*/