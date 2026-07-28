class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> res(gain.size()+1,0);
        int n=gain.size();
        for(int i=1;i<n+1;i++){
            res[i]=res[i-1]+gain[i-1];
        }
        int max=INT_MIN;
        for(int i=0;i<gain.size()+1;i++){
            if(res[i]>max){
                max=res[i];
            }
        }
        return max;
    }
};