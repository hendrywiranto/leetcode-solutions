class Solution {
public:

    int countSubstrings(string s) {
        int result = 0;
        this->s = s;
        this->dp = vector(s.size(), vector<int> (s.size()+1, -1));

        for(int i=s.size();i>=2;i--){
            for(int j=0;j<=s.size()-i;j++){
                result += checkPalindrome(j, i);
            }
        }

        return result + s.size();
    }

private:
    vector<vector<int>> dp;
    string s;

    int checkPalindrome(int start, int size){
        if(dp[start][size] >= 0){
            return dp[start][size];
        }

        if(size <= 0) return 0;
        if(size == 1){
            dp[start][size] = 1;
            return dp[start][size];
        }

        if(s[start] == s[start+size-1]){
            dp[start][size] = (size == 2) ? 1 : checkPalindrome(start+1, size-2);
        }
        else dp[start][size] = 0;

        return dp[start][size];
    }
};
