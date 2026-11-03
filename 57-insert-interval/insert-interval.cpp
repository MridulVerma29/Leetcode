class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> copy(intervals);
        copy.push_back(newInterval);
        sort(copy.begin(),copy.end());
        int n=copy.size();
        vector<vector<int>> res;
        vector<int> prev=copy[0];
        for(int i=1;i<n;i++){
            if(copy[i][0]<=prev[1]){
                prev[1]=max(prev[1],copy[i][1]);
            }
            else{
                res.push_back(prev);
                prev=copy[i];
            }
        }
        res.push_back(prev);
        return res;
    }
};