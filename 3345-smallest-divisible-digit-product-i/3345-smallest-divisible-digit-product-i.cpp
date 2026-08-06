class Solution {
private:
    int product(int n){
        int pro=1;
        while(n>0){
            int rem=n%10;
            pro*=rem;
            n/=10;
        }
        return pro;
    }
public:
    int smallestNumber(int n, int t) {
        while(n){
            if(product(n)%t==0){
                return n;
            }
            else{
                n++;
            }
        }
        return 0;
    }
};