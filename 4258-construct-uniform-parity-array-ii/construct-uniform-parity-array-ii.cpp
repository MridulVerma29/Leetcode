class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minval=INT_MAX;
        for(int num:nums1){
            if(num%2!=0){
                minval=min(num,minval);
            }
        }
        if(minval==INT_MAX) return true;
        for(int num:nums1){
            if(num%2==0 && num<minval) return false;
        }
        return true;
    }
};