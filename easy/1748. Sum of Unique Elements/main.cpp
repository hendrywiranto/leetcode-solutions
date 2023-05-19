class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> memo;

        for(int i=0;i<nums.size();i++){
            memo[nums[i]]++;
        }

        int result = 0;
        for(int i=0;i<nums.size();i++){
            if(memo[nums[i]] == 1) result += nums[i];
        }

        return result;
    }
};
