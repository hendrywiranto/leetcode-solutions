class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;

        // build the recommendation map
        for(int i=0;i<products.size();i++){
            for(int j=0;j<products[i].size();j++){
                mp[products[i].substr(0, j+1)].push(products[i]);
            }
        }

        vector<vector<string>> result;

        for(int i=0;i<searchWord.size();i++){
            priority_queue<string, vector<string>, greater<string>> pq = mp[searchWord.substr(0, i+1)];

            int answerCounter = 0;
            vector<string> vc;

            while(answerCounter < 3 && !pq.empty()){
                vc.push_back(pq.top());
                pq.pop();
                answerCounter++;
            }
            result.push_back(vc);
        }

        return result;
    }
};
