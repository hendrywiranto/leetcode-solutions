class Solution {
private:
    int findPivot(vector<int> nums){
        int left = 0, right = nums.size()-1, mid;

        while(left < right){
            mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }

        return left;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int left = 0, right = nums.size()-1, mid;

        while(left <= right){
            mid = left + (right - left) / 2;
            int realMid = (mid + pivot) % nums.size();

            if(nums[realMid] == target) return realMid;
            else if(nums[realMid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};
