class Solution {
public:
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
        set<char> strset={'a','e','i','o','u','A','E','I','O','U'};
        while(i<j){
            if(strset.count(s[i]) && strset.count(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(strset.count(s[i])==0 && strset.count(s[j])) i++;
            else j--;
        }
        return s;
    }
};