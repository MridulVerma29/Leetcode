class Solution {
public:
    int minRotations(string s) {
        int sum=0;
        int pointer=0;
        for(char ch:s){
            int digit=ch-'0';
            int diff=abs(pointer-digit);
            sum+=min(diff,10-diff);
            pointer=digit;
        }
        
        return sum;
    }
};