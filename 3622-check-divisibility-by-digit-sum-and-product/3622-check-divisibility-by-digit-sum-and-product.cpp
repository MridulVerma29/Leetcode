class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int x=n;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            pro*=rem;
            n/=10;
        }
        if(x%(sum+pro)==0) return true;
        return false;
    }
};