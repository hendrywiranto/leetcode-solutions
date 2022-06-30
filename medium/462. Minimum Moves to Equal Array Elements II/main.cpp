class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int medianNumber = nums[nums.size()/2];
        int result = 0;

        for(int i=0;i<nums.size();i++){
            result += abs(medianNumber - nums[i]);
        }

        return result;
    }
};
