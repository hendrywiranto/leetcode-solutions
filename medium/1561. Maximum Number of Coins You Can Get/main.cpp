class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int result = 0;
        int div = piles.size() / 3;
        int additionCount = 0;
        for(int i=piles.size()-2;i>=0 && additionCount<div;i-=2){
            result += piles[i];
            additionCount++;
        }

        return result;
    }
};
