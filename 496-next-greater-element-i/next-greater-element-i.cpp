class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int num: nums1){
            for(int i=0;i<nums2.size();i++){
                if(num==nums2[i]){
                    int ans=-1;
                    for(int j=i+1;j<nums2.size();j++){
                        if(nums2[j]>num){
                            ans=nums2[j];
                            break;
                        }
                    }
                    res.push_back(ans);
                    break;
                }
            }
        }
        return res;
    }
};