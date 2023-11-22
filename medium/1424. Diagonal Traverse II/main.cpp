class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> mapper;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mapper[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> result;
        for(auto m:mapper){
            for(int i=m.second.size()-1;i>=0;i--){
                result.push_back(m.second[i]);
            }
        }

        return result;
    }
};
