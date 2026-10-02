class Solution {
private:
    bool isvalid(string& s){
        int count=0;
        for( char ch:s){
            if(ch=='('){
                count++;
            }
            else{
                count--;
            }
            if(count<0) return false;
        }
        return count==0;
    }
    vector<string> res;
    void solve(string& curr,int n){
        if(curr.size()==2*n){
            if(isvalid(curr)){
                res.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n);
        return res;
    }
};