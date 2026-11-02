class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=nums.size()/2;
        int median=nums[mid];
        long long moves=0;
        for(int x:nums){
            moves+=abs(x-median);
            // [1,2,9,10]
            // median=2
            // (x-median)=1+0+7+8-->16
        }
        return moves;
    }
};