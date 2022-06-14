class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        dp = vector(m, vector<int>(n, -1));

        int lcs = LCS(word1, word2, m-1, n-1);
        return (m - lcs) + (n - lcs);
    }
private:
    vector<vector<int>> dp;

    int LCS(string word1, string word2, int p1, int p2) {
        if(p1 < 0 || p2 < 0) return 0;
        if(dp[p1][p2] != -1) return dp[p1][p2];

        if(word1[p1] == word2[p2]){
            dp[p1][p2] = 1 + LCS(word1, word2, p1-1, p2-1);
        }
        else {
            dp[p1][p2] = max(LCS(word1, word2, p1-1, p2), LCS(word1, word2, p1, p2-1));
        }

        return dp[p1][p2];
    }
};
