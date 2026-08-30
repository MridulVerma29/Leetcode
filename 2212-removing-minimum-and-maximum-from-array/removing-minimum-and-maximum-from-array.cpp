class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        int minind = 0;
        int maxind = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minind = i;
            }

            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxind = i;
            }
        }

        int left = min(minind, maxind);
        int right = max(minind, maxind);

        // Both removed from left
        int option1 = right + 1;

        // Both removed from right
        int option2 = n - left;

        // One removed from left, one from right
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};