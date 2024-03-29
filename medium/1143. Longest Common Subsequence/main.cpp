class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size()+1, vector<int>(text2.size()+1, 0));

        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(text1[i] == text2[j]){
                    memo[i+1][j+1] = 1 + memo[i][j];
                }
                else {
                    memo[i+1][j+1] = max(memo[i][j+1], memo[i+1][j]);
                }
            }
        }

        return memo[text1.size()][text2.size()];
    }
};
