class Solution {
private:
    int inc(vector<int>& nums){
        int n=nums.size();
        int i=0,j=1;
        int count=1;
        int ans=1;
        if(n==1){
            return 1;
        }
        while(i<n && j<n){
            if(nums[i]<nums[j]){
                j++;
                i++;
                count++;
                ans=max(count,ans);
            }
            else{
                count=1;
                i=j;
                j=i+1;
            }
        }
        return ans;
    }
    int dec(vector<int>& nums){
        int n=nums.size();
        int i=0,j=1;
        int count=1;
        int ans=1;
        if(n==1){
            return 1;
        }
        while(i<n && j<n){
            if(nums[i]>nums[j]){
                j++;
                i++;
                count++;
                ans=max(count,ans);
            }
            else{
                count=1;
                i=j;
                j=i+1;
            }
        }
        return ans;
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(dec(nums),inc(nums));
    }
};