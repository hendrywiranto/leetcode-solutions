class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottle = 0;
        int ans = 0;
        while(numBottles > 0 || emptyBottle >= numExchange){
            ans += numBottles;
            emptyBottle += numBottles;
            numBottles = 0;
            numBottles += emptyBottle / numExchange;
            emptyBottle = emptyBottle % numExchange;
        }

        return ans;
    }
};
