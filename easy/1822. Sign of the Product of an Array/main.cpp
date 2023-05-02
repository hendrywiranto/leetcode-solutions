class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool zero = false;
        int negatives = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0) negatives++;
            if(nums[i] == 0) zero = true;
        }

        if(zero) return 0;
        else if(negatives % 2 == 0) return 1;
        else return -1;
    }
};
