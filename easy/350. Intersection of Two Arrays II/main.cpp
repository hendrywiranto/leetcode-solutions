class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(m.find(nums2[i]) != m.end() && m[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }

        return ans;
    }
};
