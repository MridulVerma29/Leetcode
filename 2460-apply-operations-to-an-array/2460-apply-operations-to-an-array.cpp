class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                nums[i-1]*=2;
                nums[i]=0;
            }
        }
        int pos=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[pos],nums[i]);
                pos++;
            }
        }
        return nums;
    }
};