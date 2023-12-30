class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> chars(26,0);

        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                chars[words[i][j]-'a']++;
            }
        }

        int n = words.size();
        for(auto c:chars){
            if(c % n != 0) return false;
        }

        return true;
    }
};
