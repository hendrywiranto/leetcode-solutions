// way less effective, should not use DP

class Solution {
private:
    vector<int> dict;

public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m1;
        int maxCount = 0;
        for(auto t : tasks){
            maxCount = max(++m1[t], maxCount);
        }
        dict = vector<int>(maxCount+1, -1);

        int result = 0;
        for (auto const& m : m1){
            int minTask = findMinimum(m.second);
            if(minTask == INT_MAX) return -1;
            result += minTask;
        }

        return result;
    }

    int findMinimum(int n){
        if(dict[n] != -1) return dict[n];

        if(n == 1) return INT_MAX;
        if(n == 2 || n == 3) return 1;

        dict[n] = 1 + min(findMinimum(n-2), findMinimum(n-3));
        return dict[n];
    }
};
