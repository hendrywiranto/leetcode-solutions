class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        vector<vector<bool>> memo(words.size(), vector<bool>(26, false));

        for(int i=0;i<words.size();i++){
            for(int a=0;a<words[i].size();a++){
                memo[i][words[i][a] - 'a'] = true;
            }

            for(int j=0;j<i;j++){
                if(!checkDuplicate(memo[i], memo[j])){
                    result = max<double>(result, words[i].size() * words[j].size());
                }
            }
        }

        return result;
    }

private:
    bool checkDuplicate(vector<bool>& a, vector<bool>& b){
        for(int i=0;i<26;i++){
            if(a[i] == true && a[i] == b[i]) return true;
        }

        return false;
    }
};
