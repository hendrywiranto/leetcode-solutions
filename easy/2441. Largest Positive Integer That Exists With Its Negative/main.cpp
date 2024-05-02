class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        map<int,int> m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]] = 1;
            if(m.find(nums[i] * -1) != m.end()) ans = max(ans, abs(nums[i]));
        }

        return ans;
    }
};
