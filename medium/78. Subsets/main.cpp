class Solution {
private:
    vector<vector<int>> ans = {};
    void createSubsets(vector<int>& nums, vector<int> curr, int l, int size){
        if(curr.size() == size) ans.push_back(curr);

        for(int i=l;i<nums.size();i++){
            curr.push_back(nums[i]);
            createSubsets(nums, curr, i+1, size);
            curr.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int i=0;i<=nums.size();i++){
            createSubsets(nums, {}, 0, i);
        }

        return ans;
    }
};
