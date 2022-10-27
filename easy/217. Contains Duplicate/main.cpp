class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> memo;

        for(int i=0;i<nums.size();i++){
            if(memo.find(nums[i]) != memo.end()) return true;

            memo[nums[i]] = true;
        }

        return false;
    }
};
