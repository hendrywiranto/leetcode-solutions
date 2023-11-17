class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxPair = 0;
        for(int i=0;i<nums.size()/2;i++){
            maxPair = max(maxPair, nums[i] + nums[nums.size()-1-i]);
        }

        return maxPair;
    }
};
