class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int mod=1e9+7;
        long long sum=0;
        vector<int> ans(k,0);
        for(int bit=30;bit>=0;bit--){
            int cnt=0;
            for(int num:nums){
                if(num & (1<<bit)) cnt++;
            }
            for (int i = 0; i < min(k, cnt); i++) {
                ans[i] |= (1 << bit);
            }
        }
        for (int num : ans) {
            sum = (sum + 1LL * num * num) % mod;
        }
        return sum;
    }
};