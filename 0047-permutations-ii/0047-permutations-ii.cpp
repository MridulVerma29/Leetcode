class Solution {
private:
    void per(int i,vector<int>nums,vector<vector<int>>&res){
        if(nums.size()==i){
            res.push_back(nums);
            return ;
        }
        unordered_set<int> st;
        for(int j=i;j<nums.size();j++){
            if(st.count(nums[j]))
                continue;
            st.insert(nums[j]);
            swap(nums[i],nums[j]);
            per(i+1,nums,res);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        per(0,nums,res);
        return res;
    }
};