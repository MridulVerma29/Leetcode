class Solution {
private:
    int dist(int pointer,int digit){
        int d=abs(pointer-digit);
        return min(d,10-d);
    }
public:
    int minRotations(int n, string s) {
        int base=0;
        int pointer=0;
        for(char ch:s){
            int digit=ch-'0';
            base+=dist(pointer,digit);
            pointer=digit;
        }
        int ans=base;
        int last=s[n-1]-'0';
        ans=min(ans,base-dist(0,s[0]-'0')+dist(0,last));
        for(int k=1;k<n;k++){
            int prev=s[k-1]-'0';
            int curr=s[k]-'0';
            int newc=base-dist(prev,curr)+dist(prev,last);
            ans=min(ans,newc);
        }
        return ans;
    }
};