class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<int,int> mp;
        for(char ch : chars){
            mp[ch]++;
        }
        int sum=0;
        for(string word:words){
            unordered_map<int,int> mp2=mp;
            bool possible=true;
            for(char ch: word){
                mp2[ch]--;
                if(mp2[ch]<0){
                    possible=false;
                    break;
                }
            }
            if(possible){    
                sum+=word.size();
            }
            
        }
        return sum;
    }
};