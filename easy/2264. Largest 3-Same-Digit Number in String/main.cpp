class Solution {
public:
    string largestGoodInteger(string nums) {
        int lengthNow = 1;
        int good = -1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) lengthNow++;
            else lengthNow = 1;

            if(lengthNow == 3) good = max(good, nums[i]-'0');
        }

        if(good == -1) return "";
        return to_string(good) + to_string(good) + to_string(good);
    }
};
