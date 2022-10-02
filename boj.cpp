#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        int num = 1;
        vector<int> v, vv;
        string str;
        
        for (int i = 0; i < len; i++)
        {
            int idx = str.find(s[i]);
            if (!idx)
            {
                //str.append(str(s[i]));
                //string tmp(1, s[i]);
                string tmp;
                tmp.push_back(s[i]);
                str.append(tmp);
                v.push_back(num++);
            }
            else if(idx)
            {
                int j = s.find(s[i]);
                v.push_back(j);
            }
        }

        int numm = 1;
        string strr;
        for (int i = 0; i < len; i++)
        {
            int idx = str.find(t[i]);
            if (!idx)
            {
                string tmp;
                tmp.push_back(t[i]);
                strr.append(tmp);
                vv.push_back(numm++);
            }
            else if (idx)
            {
                int j = t.find(t[i]);
                vv.push_back(j);
            }
        }

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
        for (int i = 0; i < vv.size(); i++)
            cout << vv[i] << " ";
        cout << endl;

        if (v == vv)
            return true;
        else
            return false;

    }

};

int main()
{
    string s = "egg", t = "add";
    cout << s.length() << "\n";
    Solution sol = Solution();
    sol.isIsomorphic(s, t);

    return 0;
}