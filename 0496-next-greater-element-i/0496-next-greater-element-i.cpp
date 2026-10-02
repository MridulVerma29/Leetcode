class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> res;
        for( int num:nums2){
            while(!st.empty() && st.top()<num){
                mp[st.top()]=num;
                st.pop();
            }
            st.push(num);  
        }
        for(int num: nums1){
                if(mp.find(num)!=mp.end()){
                    res.push_back(mp[num]);
                }
                else{
                    res.push_back(-1);
                }
            }
        return res;
    }
};