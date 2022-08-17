class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> counter;

        for(int i=0;i<s.size();i++){
            counter[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(counter[s[i]-'a'] == 1) return i;
        }

        return -1;
    }
};
