class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        memo.resize(days.back()+1, -1);

        return minCostAtDay(0, 0);
    }
private:
    vector<int> days;
    vector<int> costs;
    vector<int> memo;

    int minCostAtDay(int currDay, int i){
        if(i >= days.size()) return 0;

        if(days[i] > currDay){
            if(memo[days[i]] != -1) return memo[days[i]];

            int d = costs[0] + minCostAtDay(days[i], i+1);
            int w = costs[1] + minCostAtDay(days[i]+6, i+1);
            int m = costs[2] + minCostAtDay(days[i]+29, i+1);

            int minimum = min(d,w);
            minimum = min(minimum, m);
            memo[days[i]] = minimum;

            return minimum;
        }

        return minCostAtDay(currDay, i+1);
    }
};
