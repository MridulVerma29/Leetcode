class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        int count=0;
        for(auto x:mp){
            if(x.second==3){
                vector<int>check;
                for(int i=0;i<nums.size();i++){
                    if(x.first==nums[i]){
                        check.push_back(i);
                    }
                }
                if(check[1]-check[0]==check[2]-check[1]){
                    count++;
                }
            }  
        }
        return count;
    }
};