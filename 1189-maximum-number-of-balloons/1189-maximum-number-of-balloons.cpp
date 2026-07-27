class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        int count=0;
        for(char ch: text){
            mp[ch]++;
        }
        while(mp['b']>=1 && mp['a']>=1 && mp['l']>=2 && mp['o']>=2 && mp['n']>=1){
            mp['b']--;
            mp['a']--;
            mp['l']-=2;
            mp['o']-=2;
            mp['n']--;
            count++;
        }
        return count;
    }
};