#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return {};
		if (n == 1) return { "()" };
		vector<vector<string>> dp(n+1);
		dp[0] = { "" };
		dp[1] = { "()" };
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <i; j++) {
				for (string p : dp[j])
					for (string q : dp[i - j - 1]) {
						string str = "(" + p + ")" + q;
						cout<<str<<" "<<p<<" "<<q<<" "<<endl;
						dp[i].push_back(str);
					}
			}
		}
        for(int i=0; i<n; i++){
            cout<<i<<" ";
            for(int j=0,len=dp[i].size(); j<len; j++){
                 cout<<dp[i][j]<<" ";
            }
            cout<<endl;
           
        }
		return dp[n];
	}
};

int main()
{
    int n = 2;
    Solution b;
    vector<string> arr = b.generateParenthesis(n);
    for (int i = 0, len = arr.size(); i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}