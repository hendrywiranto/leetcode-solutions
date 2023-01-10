class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> unorderedMap;
        for(auto num:nums){
            unorderedMap[num]++;
        }
        map<int,vector<int>> orderedMap;
        for(auto m:unorderedMap){
            orderedMap[m.second * -1].push_back(m.first);
        }

        vector<int> result;
        int n = 0;
        for(auto m:orderedMap){
            for(int i=0;i<m.second.size() && n < k;i++){
                result.push_back(m.second[i]);
                n++;
            }
        }

        return result;
    }
};
