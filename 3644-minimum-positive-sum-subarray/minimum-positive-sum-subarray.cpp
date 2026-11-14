class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int minsum=INT_MAX;
        for(int k=l;k<=r;k++){
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=nums[i];
            }
            if(sum>0){
                minsum=min(minsum,sum);
            }
            for(int i=k;i<n;i++){
                sum=sum-nums[i-k]+nums[i];
                if(sum>0){
                    minsum=min(minsum,sum);
                }
            }
        }
        
        return minsum==INT_MAX?-1:minsum;
    }
};