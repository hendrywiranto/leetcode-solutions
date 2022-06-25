class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool result = false;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                if(result) return false;

                if(i-2 >=0 && i != nums.size()-1 && nums[i-2] <= nums[i]){
                    result = true;
                    continue;
                }
                if(i+1 < nums.size() && i != 1 && nums[i+1] >= nums[i-1]){
                    result = true;
                    continue;
                }
                if(i == 1 || i == nums.size()-1){
                    result = true;
                    continue;
                }

                return false;
            }
        }

        return true;
    }
};
