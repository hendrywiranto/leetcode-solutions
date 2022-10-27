class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int maxDiff = INT_MIN;

        for(int i=0;i<prices.size();i++){
            if(prices[i] < minVal){
                minVal = prices[i];
            }

            maxDiff = max(maxDiff, prices[i] - minVal);
        }

        return maxDiff;
    }
};
