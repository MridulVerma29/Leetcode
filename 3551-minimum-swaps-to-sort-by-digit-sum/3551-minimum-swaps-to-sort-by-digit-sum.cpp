class Solution {
private:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum+=digit;
            n/=10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> arr;
        for(int x: nums){
            arr.push_back({digitsum(x),x});
        }
        vector<pair<int,int>>sorted=arr;
        sort(sorted.begin(),sorted.end());
        
        unordered_map<int,int> pos;
        for(int i=0;i<n;i++){
            pos[sorted[i].second]=i;
        }
        vector<bool> vis(n,false);
        int swap=0;
        for(int i=0;i<n;i++){
            if(vis[i] || pos[arr[i].second]==i) continue;
            int cycle=0,j=i;
            while(!vis[j]){
                vis[j]=true;
                j=pos[arr[j].second];
                cycle++;
            }
            swap+=cycle-1;
        }
        return swap;
    }
};