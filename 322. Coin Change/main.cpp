class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10001, INT_MAX);
        dp[0] = 0;

        for(int currAmount=0;currAmount<=amount;currAmount++){
            for(int i=0;i<coins.size();i++){
                if(coins[i] <= currAmount){
                    int temp = currAmount - coins[i];
                    if(dp[temp] == INT_MAX) continue;

                    dp[currAmount] = min(dp[currAmount], dp[temp] + 1);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
