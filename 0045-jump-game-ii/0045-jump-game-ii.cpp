class Solution {
private:
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        int n = nums.size() - 1;

        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int ans = INT_MAX;

        for (int jump = 1; jump <= nums[index]; jump++) {
            int rec = solve(index + jump, nums, dp);

            if (rec != INT_MAX)
                ans = min(ans, 1 + rec);
        }

        return dp[index] = ans;
    }

public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};