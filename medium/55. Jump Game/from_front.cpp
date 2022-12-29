class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;

        int i = 0;
        while(i <= maxJump){
            maxJump = max(maxJump, i + nums[i]);
            if(maxJump + 1 >= nums.size()) return true;
            i++;
        }

        return false;
    }
};
