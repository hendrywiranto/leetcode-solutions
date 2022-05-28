class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());

        for(int i=0;i<=nums.size();i++){
            if(i == 0){
                for(int j=1;j<nums[i];j++){
                    result.push_back(j);
                }
            }
            else if(i == nums.size()){
                for(int j=1;j<=i - nums[i-1];j++){
                    result.push_back(nums[i-1] + j);
                }
            }
            else if(nums[i] == nums[i-1] || nums[i] == nums[i-1]+1) continue;
            else {
                for(int j=1;j<nums[i] - nums[i-1];j++){
                    result.push_back(nums[i-1] + j);
                }
            }
        }

        return result;
    }
};
