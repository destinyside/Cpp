#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        int len = n * (n + 1) / 2;
        vector<string> arr(len);
        arr.clear();
        if (n == 1)
        {
            arr.push_back("()");
        }
        else
        {
            vector<string> lastarr = generateParenthesis(n - 1);
            for (int i = 0, lastlen = lastarr.size(); i < lastlen; i++)
            {
                string o = "(" + lastarr[i] + ")";
                arr.push_back(o);
                string l = string("(") + ")" + lastarr[i];
                bool has = false;
                for (int k = 0, j = arr.size(); k < j; k++)
                {
                    if (l.compare(arr[k]) == 0)
                    {
                        has = true;
                        break;
                    }
                }
                if (!has)
                {
                    arr.push_back(l);
                }
                string r = lastarr[i] + "(" + ")";
                has = false;
                for (int k = 0, j = arr.size(); k < j; k++)
                {
                    if (r.compare(arr[k]) == 0)
                    {
                        has = true;
                        break;
                    }
                }
                if (!has)
                {
                    arr.push_back(r);
                }
                if(lastarr[i][0]=='(' && lastarr[i][1]==')'){
                    string t = lastarr[i];
                    t[0] = ')';
                    t = "((" + t;
                    has = false;
                    for (int k = 0, j = arr.size(); k < j; k++)
                    {
                        if (t.compare(arr[k]) == 0)
                        {
                            has = true;
                            break;
                        }
                    }
                    if (!has)
                    {
                        arr.push_back(t);
                    }
                } else if(lastarr[i][lastarr[i].length()-1]==')' && lastarr[i][lastarr[i].length()-2]=='('){
                    string t = lastarr[i];
                    t[lastarr[i].length()-1] = '(';
                    t = t + "))";
                    has = false;
                    for (int k = 0, j = arr.size(); k < j; k++)
                    {
                        if (t.compare(arr[k]) == 0)
                        {
                            has = true;
                            break;
                        }
                    }
                    if (!has)
                    {
                        arr.push_back(t);
                    }
                }
                //out<<"o: "<<o<<" l: "<<l<<" r: "<<r<<endl;
            }
        }
        return arr;
    }
};

int main()
{
    int n = 4;
    Solution b;
    vector<string> arr = b.generateParenthesis(n);
    for (int i = 0, len = arr.size(); i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}