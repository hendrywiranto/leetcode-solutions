class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<pair<int,int>> pq;
        vector<vector<int>> result;

        for(int i=0;i<people.size();i++){
            pq.push(make_pair(people[i][0], -1*people[i][1]));
        }

        while(!pq.empty()){
            int nowHeight = pq.top().first;
            int nowFront = pq.top().second*-1;

            result.insert(result.begin() + nowFront, {nowHeight, nowFront});
            pq.pop();
        }

        return result;
    }
};
