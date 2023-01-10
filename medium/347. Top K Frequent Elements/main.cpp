class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ms;

        for(auto num:nums){
            ms[num]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto m:ms){
            pq.push(make_pair(m.second, m.first));
        }

        vector<int> result;
        while(k >= 1){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};
