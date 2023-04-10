class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxDiff = 0;

        for(auto p:prices){
            minPrice = min(minPrice, p);
            maxDiff = max(p - minPrice, maxDiff);
        }

        return maxDiff;
    }
};
