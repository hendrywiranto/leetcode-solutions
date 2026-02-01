class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first;
        int min = 51;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < min){
                min = nums[i];
                first = i;
            }
        }

        int second;
        min = 51;
        for(int i=1;i<nums.size();i++){
            if(i == first) continue;

            if(nums[i] < min){
                min = nums[i];
                second = i;
            }
        }

        return nums[0] + nums[first] + nums[second];
    }
};
