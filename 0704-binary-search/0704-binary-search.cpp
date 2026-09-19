class Solution {
private:
    int bsearch(vector<int>& nums,int s,int e,int target){
        if(s>e)return -1;
        int mid=(s+e) /2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>target){
            return bsearch(nums,s,mid-1,target);
            
        }
        else return bsearch(nums,mid+1,e,target);
    }
public:
    int search(vector<int>& nums, int target) {
        return bsearch(nums,0,nums.size()-1,target);
    }
};