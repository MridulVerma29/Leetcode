class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[i] = true means the current player can win
        // when there are i stones remaining.

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                // If we can make a move that leaves
                // the opponent in a losing state
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};