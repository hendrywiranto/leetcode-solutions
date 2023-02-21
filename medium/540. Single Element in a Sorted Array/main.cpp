class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        int mid;

        while(left <= right){
            mid = left + (right - left) / 2;

            if(mid-1 >= 0 && nums[mid-1] == nums[mid]){
                if((mid-1) % 2 == 1){
                    right = mid-2;
                }
                else {
                    left = mid+1;
                }
            }
            else if(mid+1 <= nums.size()-1 && nums[mid] == nums[mid+1]){
                if(mid % 2 == 0){
                    left = mid+2;
                }
                else {
                    right = mid-1;
                }
            }
            else {
                return nums[mid];
            }
        }

        return 0;
    }
};
