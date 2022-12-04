class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int fTotal  = 0, bTotal = 0;
        int minDiff = INT_MAX, minDiffIndex = 0;

        for(int i=0;i<nums.size();i++){
            bTotal += nums[i];
        }
        for(int i=0;i<nums.size();i++){
            bTotal -= nums[i];
            fTotal += nums[i];

            int last = 0;
            if (i != nums.size()-1) last = bTotal / (nums.size() - i - 1);

            int diff = abs((fTotal / (i+1)) - last);
            if(diff < minDiff){
                minDiff = diff;
                minDiffIndex = i;
            }
        }

        return minDiffIndex;
    }
};
