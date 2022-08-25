class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> mp;

        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i] - 'a']++;
        }
        for(int i=0;i<magazine.size();i++){
            mp[magazine[i] - 'a']--;
        }

        for(auto it:mp){
            if(it.second > 0) return false;
        }

        return true;
    }
};
