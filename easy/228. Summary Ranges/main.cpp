class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result(0);
        if(nums.size() == 0) return result;

        int low = nums[0];
        int high = low;

        for(int i=1;i<nums.size();i++){
            if(high+1 != nums[i]){
                if(low != high) result.push_back(to_string(low) + "->" + to_string(high));
                else result.push_back(to_string(low));

                low = nums[i];
            }
            high = nums[i];
        }

        if(low == high) result.push_back(to_string(low));
        else result.push_back(to_string(low) + "->" + to_string(high));

        return result;
    }
};
