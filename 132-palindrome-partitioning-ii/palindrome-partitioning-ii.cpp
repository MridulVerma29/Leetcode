class Solution {
private:
    int palindrome(int i,int j,string& s){
        while(i<=j){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }

    int fact(int i,string& s,vector<int>& dp){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int m=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(palindrome(i,j,s)){
                int count=1+fact(j+1,s,dp);
                m=min(count,m);
            }
        }
        return dp[i]=m;
    }
public:
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return fact(0,s,dp)-1;
    }
};