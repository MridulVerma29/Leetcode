class Solution {
private:
    bool palindrome(string& s,int left,int right,int deleted){
        if (left >= right) return true;
        if(s[left]==s[right]){
           return palindrome(s,left+1,right-1,deleted);
        }
        if(deleted==1) return false;
        return palindrome(s,left+1,right,1)||palindrome(s,left,right-1,1);

    }
public:
    bool validPalindrome(string s) {
        return palindrome(s,0,s.size()-1,0);
    }
};