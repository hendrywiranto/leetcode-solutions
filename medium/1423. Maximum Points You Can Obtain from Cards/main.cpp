class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int result = 0;
        int n = cardPoints.size();

        cardPoints.insert(cardPoints.begin(), 0);
        for(int i=1;i<=n;i++){
            cardPoints[i] += cardPoints[i-1];
        }

        for(int i=0;i<=k;i++){
            result = max(result, cardPoints.back() - (cardPoints[i + n - k] - cardPoints[i]) );
        }

        return result;
    }
};
