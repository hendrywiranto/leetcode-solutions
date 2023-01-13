class Solution {
private:
    vector<int> maxAtHouse;
public:
    int rob(vector<int>& nums) {
        maxAtHouse.resize(nums.size());
        int globalMax = 0;

        for(int i=nums.size()-1;i>=0;i--){
            maxAtHouse[i] = findMax(nums, i);
            globalMax = max(globalMax, maxAtHouse[i]);
        }

        return globalMax;
    }

    int findMax(vector<int>& nums, int i){
        if(i == nums.size()-1 || i == nums.size()-2) return nums[i];

        int localMax = 0;
        for(int j=i+2;j<nums.size();j++){
            localMax = max(localMax, maxAtHouse[j]);
        }

        return nums[i] + localMax;
    }
};
