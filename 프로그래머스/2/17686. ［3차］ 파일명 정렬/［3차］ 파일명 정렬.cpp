#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    string ahead, bhead, anum="", bnum="";
    
    bool isA = true, isB = true;
    int cnt = 0;
    for (int i=0; i<a.size(); ++i)
    {
        if (a[i] >= '0' && a[i] <= '9' && cnt < 5)
        {
            ++cnt;
            isA = false;
            if (anum == "" && a[i] == '0')
                continue;
            anum += a[i];
        }
        else if (isA)
            ahead += a[i];
        else
            break;
    }
    cnt = 0;
    for (int i=0; i<b.size(); ++i)
    {
        if (b[i] >= '0' && b[i] <= '9' && cnt < 5)
        {
            ++cnt;
            isB = false;
            if (bnum == "" && b[i] == '0')
                continue;
            bnum += b[i];
        }
        else if (isB)
            bhead += b[i];
        else
            break;
    }    
    std::transform(ahead.begin(), ahead.end(), ahead.begin(), ::tolower);
    std::transform(bhead.begin(), bhead.end(), bhead.begin(), ::tolower);
    
    if (ahead == bhead)
    {
        if (anum == "") anum = '0';
        if (bnum == "") bnum = '0';
        return stoi(anum) < stoi(bnum);
    }
    else
        return ahead < bhead;
    
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}