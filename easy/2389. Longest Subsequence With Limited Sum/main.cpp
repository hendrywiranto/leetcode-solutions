class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        priority_queue<int> pq;

        for(auto num:nums){
            pq.push(num*-1);
        }

        vector<int> answers;
        for(auto query:queries){
            priority_queue<int> temp = pq;
            int result = 0;

            while(!temp.empty()){
                query += temp.top();
                if(query < 0) break;
                result++;
                temp.pop();
            }
            answers.push_back(result);
        }

        return answers;
    }
};
