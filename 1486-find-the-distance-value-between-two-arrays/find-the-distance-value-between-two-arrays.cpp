class Solution {
private:
    bool  isvalid(int n,vector<int>& arr2,int d){
        for(int e:arr2){
            if(abs(e-n)<=d) return false;
        }
        return true;
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c=0;
        for(int n:arr1){
            if(isvalid(n,arr2,d)) c++;
        }
        return c;
    }
};