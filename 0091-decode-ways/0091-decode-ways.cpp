class Solution {
private:
    int solve(string& s, int i, vector<int>& dp) {
        int n = s.size();

        if (i == n) return 1;

        // Current digit cannot be 0
        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        // Take one digit
        int ways = solve(s, i + 1, dp);

        // Take two digits
        if (i + 1 < n &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ways += solve(s, i + 2, dp);
        }

        return dp[i] = ways;
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return solve(s, 0, dp);
    }
};