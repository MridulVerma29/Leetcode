class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        // in
        while(left<right){
            int currsum=numbers[left]+numbers[right];
            if(currsum==target) return {left+1,right+1};
            if(currsum> target) right--;
            else left++;
        }
        return {0,0};
    }
};