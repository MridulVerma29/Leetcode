class Solution {
public:
    int minDays(int n) {
        const int INF=1e9;
        vector<int> dp(n+1,INF);
        dp[0]=-1;
        for(int score=1;score<=n;score++){
            for(int k=1;k*(k+1)/2<=score;k++){
                int points=k*(k+1)/2;
                dp[score]=min(dp[score],dp[score-points]+k+1);
            }
        }
        return dp[n];
    }
};