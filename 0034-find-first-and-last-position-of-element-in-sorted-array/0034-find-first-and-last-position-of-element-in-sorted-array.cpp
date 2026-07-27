class Solution {
public:
    int first(vector<int>& nums, int target) {
        int start=0;
        int ans=-1;
        int n=nums.size();
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target == nums[mid]){
                ans=mid;
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    };
    int end(vector<int>& nums, int target) {
        int start=0;
        int ans=-1;
        int n=nums.size();
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target == nums[mid]){
                ans=mid;
                start=mid+1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    };
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first( nums, target),end( nums, target)};
    }

};