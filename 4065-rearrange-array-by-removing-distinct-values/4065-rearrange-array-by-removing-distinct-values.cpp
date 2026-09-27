class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        vector<int> ans;
        while(!freq.empty()){
            vector<int> remove;
            for(auto &[value,count]: freq){
                ans.push_back(value);
                count--;
                if(count==0){
                    remove.push_back(value);
                }
            }
            for(int x:remove){
                freq.erase(x);
            }
        }
        return ans;
    }
};