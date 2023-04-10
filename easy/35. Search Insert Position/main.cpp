class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;

        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;

            if(mid-1 >= 0 && nums[mid-1] < target && target < nums[mid]) return mid;
            else if(mid == 0 && target < nums[mid]) return 0;

            if(mid+1 <= nums.size()-1 && nums[mid] < target && target < nums[mid+1]) return mid+1;
            else if(mid == nums.size()-1 && nums[mid] < target) return nums.size();
        }

        return mid;
    }
};
