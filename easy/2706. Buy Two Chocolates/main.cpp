class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = prices[0], second = INT_MAX;

        for(int i=1;i<prices.size();i++){
            if(first > prices[i]){
                second = first;
                first = prices[i];
            } else if(second > prices[i]) second = prices[i];
        }

        if(money < first + second) return money;
        else return money - first - second;
    }
};
