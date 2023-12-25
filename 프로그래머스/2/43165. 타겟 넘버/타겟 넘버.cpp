#include <bits/stdc++.h>
using namespace std;

void combi(const vector<int>& numbers, vector<bool> operation, const int& target, int& answer)
{
    int _size = operation.size();
    if (_size == numbers.size())
    {
        int _sum=0;
        for (int i=0; i<_size; ++i)
        {
            if (operation[i]) _sum += numbers[i];
            else _sum -= numbers[i];
        }
        if (_sum == target)
            ++answer;
        return;
    }
    
    for (int i=0; i<2; ++i)
    {
        bool val;
        if (i%2==0) val = true;
        else val = false;
        
        operation.push_back(val);
        combi(numbers, operation, target, answer);
        operation.pop_back();
    }
}

// 2^20 => 1,000^2 => 1,000,000
int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<bool> op;
    combi(numbers, op, target, answer);
    return answer;
}