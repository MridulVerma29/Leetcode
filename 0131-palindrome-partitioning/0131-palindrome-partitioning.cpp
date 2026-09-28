class Solution {
private:
    bool isPalindrome(string s){
        string rev=s;
        reverse(rev.begin(),rev.end());
        if(s==rev) return true;
        return false;
    }
    void solve(string s,int index, int n,vector<string> &v,vector<vector<string>>& ans){
        if(index==n){
            ans.push_back(v);
            return ;
        }
        for(int i=index;i<n;i++){
            string str=s.substr(index,i-index+1);
            if(isPalindrome(str)){
                v.push_back(str);
                solve(s,i+1,n,v,ans);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string> v;
        solve(s,0,n,v,ans);
        return ans;
    }
};