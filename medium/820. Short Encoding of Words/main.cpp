class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.length() > b.length();
        });

        unordered_map<string,int> mp;
        int result = 0;

        for(int i=0;i<words.size();i++){
            if(mp.find(words[i]) != mp.end()) continue;

            result += words[i].size() + 1;

            for(int j=words[i].size()-1;j>=0;j--){
                mp[words[i].substr(j, words[i].size()-j)] = 1;
            }
        }

        return result;
    }
};
