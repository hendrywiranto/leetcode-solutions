class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> pos;
        int result = 0, now = 0;
        int left = 0, right = 0;

        while(right <= nums.size()-1){
            if(pos.find(nums[right]) != pos.end()){
                while(left <= pos[nums[right]]){
                    now -= nums[left];
                    pos.erase(nums[left]);
                    left++;
                }

                pos[nums[right]] = right;
                now += nums[right];
                result = max(result, now);
            }
            else {
                pos[nums[right]] = right;
                now += nums[right];
                result = max(result, now);
            }
            right++;
        }

        return result;
    }
};
