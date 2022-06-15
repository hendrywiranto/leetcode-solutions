class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> mp;

        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.length() < b.length();
        });

        int result = 0;
        for(int i=0;i<words.size();i++){
            mp[words[i]] = 1;

            for(int j=0;j<words[i].size();j++){
                string tmp = words[i];
                tmp.erase(j, 1);

                if(mp.find(tmp) != mp.end()){
                    mp[words[i]] = max(mp[words[i]], mp[tmp] + 1);
                }
            }

            result = max(result, mp[words[i]]);
        }

        return result;
    }
};
