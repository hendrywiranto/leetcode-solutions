class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> ans;
        traverse(0, nums, temp, ans);

        return vector(ans.begin(), ans.end());
    }

    void traverse(int start, vector<int> &nums, vector<int> &temp, set<vector<int>> &ans){
        if(temp.size() >= 2){
            ans.insert(temp);
        }

        for(int i=start;i<nums.size();i++){
            if(!temp.empty() && temp.back() > nums[i]) continue;

            temp.push_back(nums[i]);
            traverse(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }
};
