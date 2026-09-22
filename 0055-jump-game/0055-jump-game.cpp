class Solution {
bool solve(int index,vector<int>&  nums,vector<int>& dp){
    int n=nums.size()-1;
    if(index==n) return true;
    if(index>n) return false;
    if(nums[index]==0) return false;
    if(dp[index]!=-1) return dp[index];
    int jumpval=nums[index];
    for(int jump=1;jump<=jumpval;jump++){
        if(solve(index+jump,nums,dp)) return dp[index]=true;
    }
    return dp[index]=false;
    
}
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};