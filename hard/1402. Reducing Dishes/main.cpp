class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int result = 0, substractSum = 0;
        for(int i=1;i<=satisfaction.size();i++){
            substractSum += satisfaction[i-1];
            result += satisfaction[i-1] * i;
        }
        int currentSum = result;

        for(int i=0;i<satisfaction.size();i++){
            currentSum -= substractSum;
            result = max(result, currentSum);
            substractSum -= satisfaction[i];
        }

        return result;
    }
};
