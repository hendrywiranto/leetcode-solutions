class Solution {
public:
    int partitionString(string s) {
        vector<bool> m(26, false);
        int result = 0;
        for(int i=0;i<s.size();i++){
            if(m[s[i] - 'a']){
                result++;
                m = vector<bool>(26, false);
            }

            m[s[i] - 'a'] = true;
        }

        return result + 1;
    }
};
