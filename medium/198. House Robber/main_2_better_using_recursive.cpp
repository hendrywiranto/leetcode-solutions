class Solution {
private:
    vector<int> memo;
public:
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return findMax(nums, nums.size()-1);
    }

    int findMax(vector<int>& nums, int i){
        if(i < 0) return 0;
        if(memo[i] != -1) return memo[i];

        memo[i] = max(nums[i] + findMax(nums, i-2), findMax(nums, i-1));
        return memo[i];
    }
};
