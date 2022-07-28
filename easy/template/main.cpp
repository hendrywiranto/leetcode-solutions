class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> dict;
        for(int i=0;i<s.size();i++){
            dict[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(dict.find(t[i]) == dict.end() || dict[t[i]] <= 0){
                return false;
            }

            dict[t[i]]--;
        }

        return true;
    }
};
