class Solution {
private:
    void per(int i,vector<int>nums,vector<vector<int>>& res){
        if(nums.size()==i){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            per(i+1,nums,res);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        per(0,nums,res);
        return res;
    }
};