class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,int>> pq;
        vector<int> dict(75,0);

        for(int i=0;i<s.size();i++){
            dict[s[i] - '0']++;
        }
        for(int i=0;i<75;i++){
            if(dict[i] != 0) pq.push(make_pair(dict[i], i));
        }

        string res = "";
        while(!pq.empty()){
            auto temp = pq.top();
            int times = temp.first;

            while(times > 0){
                res += temp.second + '0';
                times--;
            }
            pq.pop();
        }

        return res;
    }
};
