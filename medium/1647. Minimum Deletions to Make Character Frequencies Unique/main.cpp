class Solution {
public:
    int minDeletions(string s) {
        vector<int> mp(26, 0);
        priority_queue<int> pq;
        int result = 0;

        // count each char
        for(int i=0;i<s.size();i++){
            mp[s[i] - 'a']++;
        }

        // push frequencies into the PQ
        for (int i=0;i<26;i++){
            if(mp[i] > 0) pq.push(mp[i]);
        }

        // reduct count until there is unique frequencies
        int now = pq.top();
        pq.pop();
        while(!pq.empty()){
            if(now == pq.top()){
                if(now - 1 != 0) pq.push(now - 1);
                result++;
            }
            now = pq.top();
            pq.pop();
        }

        return result;
    }
};
