class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int> pq;
        int totalIceCream = 0;

        for(auto cost : costs){
            pq.push(cost * -1);
        }
        while(!pq.empty() && pq.top() * -1 <= coins){
            totalIceCream++;
            coins += pq.top();
            pq.pop();
        }

        return totalIceCream;
    }
};
