class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> memo(2001, 0);

        for(auto n:nums1){
            memo[n + 1000]++;
        }
        for(auto n:nums2){
            if(memo[n + 1000] > 0) memo[n + 1000] *= -1;
        }

        set<int> r1, r2;
        for(auto n:nums1){
            if(memo[n + 1000] > 0) r1.insert(n);
        }
        for(auto n:nums2){
            if(memo[n + 1000] == 0) r2.insert(n);
        }
        vector<int> v1(r1.begin(), r1.end());
        vector<int> v2(r2.begin(), r2.end());

        return { v1, v2 };
    }
};
