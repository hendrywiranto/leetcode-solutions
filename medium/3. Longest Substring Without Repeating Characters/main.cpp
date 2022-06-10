class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int f = 0, b = 0, result = 0, now = 0;
        map<char,int> mp;

        while(b < s.size()){
            now++;
            if(mp[s[b]] != 0){
                while(f <= b) {
                    mp[s[f]] = 0;
                    f++;
                    now--;

                    if(s[f-1] == s[b]) break;
                }
            }

            mp[s[b]] = 1;
            result = max(result, now);
            b++;
        }

        return result;
    }
};
