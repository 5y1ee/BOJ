#include <bits/stdc++.h>
using namespace std;

void func(vector<bool>& v, const vector<int>& num, const int n_size, const int target, int& answer)
{
    if (v.size() == n_size)
    {
        int sum=0;
        for (int i=0; i<n_size; ++i)
        {
            if (v[i])
                sum += num[i];
            else
                sum -= num[i];            
        }
        if (sum == target)
            ++answer;
        return;
    }
    
    for (int i=0; i<2; ++i)
    {
        if (i%2 == 0)
            v.push_back(true);
        else
            v.push_back(false);
        
        func(v, num, n_size, target, answer);
        v.pop_back();        
    }
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n_size = numbers.size();
    
    vector<bool> v;
    func(v, numbers, n_size, target, answer);
    
    return answer;
}