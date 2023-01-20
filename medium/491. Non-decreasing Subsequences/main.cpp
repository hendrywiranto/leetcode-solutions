class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        map<vector<int>,bool> memo;

        for(int k=1;k<nums.size();k++){
            int n = result.size();

            for(int i=0;i<k;i++){
                if(nums[i] <= nums[k]){
                    vector<int> temp = {nums[i], nums[k]};
                    if(memo.find(temp) == memo.end()){
                        result.push_back(temp);
                        memo[temp] = true;
                    }
                }
            }

            for(int i=0;i<n;i++){
                if(result[i].back() <= nums[k]){
                    vector<int> temp = result[i];
                    temp.push_back(nums[k]);
                    if(memo.find(temp) == memo.end()){
                        result.push_back(temp);
                        memo[temp] = true;
                    }
                }
            }
        }

        return result;
    }
};
