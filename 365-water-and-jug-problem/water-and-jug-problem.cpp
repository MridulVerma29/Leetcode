class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y <target) return false;
        int gcd1=gcd(x,y);
        if(target%gcd1==0) return true;
        return false;
    }
};