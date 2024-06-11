class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> m;

        for(int i=0;i<arr2.size();i++){
            m[arr2[i]] = 0;
        }

        priority_queue<int> pq;
        for(int i=0;i<arr1.size();i++){
            if(m.find(arr1[i]) == m.end()) pq.push(arr1[i] * -1);
            else m[arr1[i]]++;
        }

        vector<int> ans;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<m[arr2[i]];j++) ans.push_back(arr2[i]);
        }

        while(!pq.empty()){
            ans.push_back(pq.top() * -1);
            pq.pop();
        }

        return ans;
    }
};
