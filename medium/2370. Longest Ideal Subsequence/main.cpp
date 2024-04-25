class Solution {
private:
    int countLongest(vector<vector<int>> &memo, string &s, int &k, int i, int last){
        if(i >= s.size()) return 0;
        if(memo[i][last] != -1) return memo[i][last];

        int taken = 0, skip = 0;
        if(last == 0 || abs(last - (s[i]-'a'+1)) <= k) taken = 1 + countLongest(memo, s, k, i+1, s[i]-'a'+1);

        skip = countLongest(memo, s, k, i+1, last);
    
        memo[i][last] = max(taken, skip);
        return memo[i][last];
    }
public:
    int longestIdealString(string s, int k) {
        vector<vector<int>> memo(s.size(), vector<int>(27, -1));

        return countLongest(memo, s, k, 0, 0);
    }
};
