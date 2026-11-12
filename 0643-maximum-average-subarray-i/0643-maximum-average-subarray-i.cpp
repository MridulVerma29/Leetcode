class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();

        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maxsum=sum;
        for(int i=k;i<n;i++){
            sum=nums[i]-nums[i-k]+sum;
            maxsum=max(maxsum,sum);
        }
        double avg=(double)maxsum/k;
        return avg;
    }
};