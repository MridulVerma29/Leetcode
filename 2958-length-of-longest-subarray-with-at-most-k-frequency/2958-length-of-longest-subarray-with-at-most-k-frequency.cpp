class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        // for(int num:nums){
        //     mp[num]++;
        // } 
        // int count=0;
        // for(auto i: mp){
        //     if(i.second>=k){
        //         count+=k;
        //     }
        //     else if(i.second<k){
        //         count+=i.second;
        //     }
        // }
        // return count;
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};