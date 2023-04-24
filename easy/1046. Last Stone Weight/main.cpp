class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto s:stones) pq.push(s);

        while(pq.size() > 1){
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            int remains = abs(first - second);

            if(remains != 0) pq.push(remains);
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};
