class Solution {
public:
    int countSubstrings(string s){
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        int result = 0;

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(checkPalindrome(i, j, s, memo) == 1) result++;
            }
        }

        return result;
    }

    int checkPalindrome(int l, int r, string s, vector<vector<int>> &memo){
        if(l > r) return 1;
        if(memo[l][r] != -1) return memo[l][r];

        if(s[l] != s[r]){
            memo[l][r] = 0;
            return memo[l][r];
        }

        memo[l][r] = checkPalindrome(l+1, r-1, s, memo);
        return memo[l][r];
    }
};
