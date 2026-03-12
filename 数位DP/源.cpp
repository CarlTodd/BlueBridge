#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    int dp[20];
    vector<int>dig;
    string S;
    int dfs(int pos, int limit)
    {
        if (pos == S.size())return true;
        if (!limit && dp[pos] != -1)return dp[pos];
        int up = limit ? (S[pos] - '0') : 9;
        int res = 0;
        for (int i : dig)
        {
            res += dfs(pos + 1, limit & (i == up));
        }
        if (!limit)dp[pos] = res;
        return res;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        for (string i : digits)
        {
            dig.push_back(stoi(i));
        }
        S = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(0, true);
    }

};

int main()
{
    Solution s1;
    s1.atMostNGivenDigitSet({ "1","3","5","7" },100)
}